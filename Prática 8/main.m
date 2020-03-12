% a
% ------------------------------------------------------------------------------------------------
rng('default'); % for repeatable result
dt = 0.05; % time step
initialPose = [0 0 0 0]';

carbot = ExampleHelperCarBot(initialPose, dt);
% ------------------------------------------------------------------------------------------------

% b
% ------------------------------------------------------------------------------------------------
pf = robotics.ParticleFilter;

initialize(pf, 500, [initialPose(1:3)', 0, 0, 0], eye(6), 'CircularVariables', [0 0 1 0 0 0]);
pf.StateEstimationMethod = 'mean';
pf.ResamplingMethod = 'systematic';

% StateTransitionFcn defines how particles evolve without measurment
pf.StateTransitionFcn = @exampleHelperCarBotStateTransition;

% MeasurementLikelihoodFcn defines how measurement affect the our
% estimation
pf.MeasurementLikelihoodFcn = @exampleHelperCarBotMeasurementLikelihood;

% Last best estimation for x, y and theta
lastBestGuess = [0 0 0];
% ------------------------------------------------------------------------------------------------


% c
% ------------------------------------------------------------------------------------------------
r = robotics.Rate(1/dt);
reset(r);
simulationTime = 0;
% ------------------------------------------------------------------------------------------------


% d
% ------------------------------------------------------------------------------------------------
while simulationTime < 20 % if time is not up
    uCmd(1) = 0.7*abs(sin(simulationTime)) + 0.1;
    uCmd(2) = 0.08*cos(simulationTime);
    
    drive(carbot, uCmd);
    
    [statePred, covPred] = predict(pf, dt, uCmd);
    
    measurement = exampleHelperCarBotGetGPSReading(carbot);
    
    if ~isempty(measurement)
        [stateCorrected, covCorrected] = correct(pf, measurement');
    else
        stateCorrected = statePred;
        covCorrected = covPred;
    end
    
    lastBestGuess = stateCorrected(1:3);
    
    % Update plot
    if ~isempty(get(groot,'CurrentFigure')) % if figure is not prematurely killed
        updatePlot(carbot,pf, lastBestGuess, simulationTime);
    else
        break
    end
    
    waitfor(r);
    
    % Update simulation time
    simulationTime = simulationTime + dt;
end