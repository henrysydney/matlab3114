%% DC motor parameters

Rm = 8.4; %Ohm
Km = 0.042; %N.m/A
Kb = 0.042; %V/rad/s
Jm = 4*10^(-6); %Kg.m^2
Lm = 1.16e-3; %H

%Load hub parameters 
mh = 0.0106; %kg
rh = 0.0111; %m

%Load disk parameters 
md = 0.053; %kg 
rd = 0.0248; %m 

% Calculate moment of inertia for the disk and the hub
Jh = 1/2*mh*(rh^2); %kg-m^2
Jd = 1/2*md*(rd^2); %kg-m^2
Jeq = Jm+Jh+Jd; %kg-m^2