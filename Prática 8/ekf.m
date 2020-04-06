rng('default'); % for repeatable result
dt = 0.05; % time step
initialPose = [0 0 0 0]';
carbot = Bot(initialPose, dt);

EKF = trackingEKF(@constvel,@cvmeas,[0;0;0;0], ...
    'StateTransitionJacobianFcn',@constveljac, ...
    'MeasurementJacobianFcn',@cvmeasjac);

r = robotics.Rate(1/dt);
reset(r);
simulationTime = 0;

while simulationTime < 20 % if time is not up
    % Generate motion command that is to be sent to the robot
    % NOTE there will be some discrepancy between the commanded motion and the
    % motion actually executed by the robot.
    uCmd(1) = 0.7*abs(sin(simulationTime)) + 0.1; % linear velocity
    uCmd(2) = 0.08*cos(simulationTime); % angular velocity
    drive(carbot, uCmd);
    % Predict the carbot pose based on the motion model
    [statePred, covPred] = predict(EKF);
    % Get GPS reading
    measurement = exampleHelperCarBotGetGPSReading(carbot);
    % If measurement is available, then call correct, otherwise just use
    % predicted result
    if ~isempty(measurement)
        [stateCorrected, covCorrected] = correct(EKF, ...
        measurement');
    else
        stateCorrected = statePred;
        covCorrected = covPred;
    end
    
    lastBestGuess = stateCorrected(1:3);
    
    % Update plot
    if ~isempty(get(groot,'CurrentFigure')) % if figure is not prematurely killed
        updatePlot(carbot, EKF ,lastBestGuess, simulationTime);
    else
        break
    end
    
    waitfor(r);
    % Update simulation time
    simulationTime = simulationTime + dt;
end


