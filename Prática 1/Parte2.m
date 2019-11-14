
ipaddress = input('IP_OF_VM: ', 's');
try
    rosinit(ipaddress);
catch
    rosshutdown;
    rosinit(ipaddress);
end
    
input("rosinit started\nEnter to continue", 's');

handles.odomSub = rossubscriber('/odom', 'BufferSize', 25);
receive(handles.odomSub,3);
handles.laserSub = rossubscriber('/scan', 'BufferSize', 5);
receive(handles.laserSub,3);

input("odomSub and laserSub\nEnter to continue", 's');

handles.velPub = rospublisher('/mobile_base/commands/velocity');

input("velPub\nEnter to continue", 's');

exampleHelperTurtleBotKeyboardControl(handles);
