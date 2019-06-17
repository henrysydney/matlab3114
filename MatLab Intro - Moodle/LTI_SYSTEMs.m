%% Loading and running a Simulink model
   clc; clear; close all;

% Opening Simulink
   simulink

% Opening Simulink library
%  slLibraryBrowser

% Define value for gains a1 & a2
   a1 = 2; 
   a2 = 3;

%% Stability, step/inputs response plotting and closed-loop systems
   clc; clear ;

   s = tf('s')
   G1 = 1/(s^2+6*s+5);
   zero(G1);
   pole(G1);
   DCGain = dcgain(G1);

  % figure(1);
   step(G1);
   stepinfo(G1);

  % figure(2);
   impulse(G1);
   stepinfo(impulse(G1));
   
 % Closed loop system
   %help feedback
   %G1 is transfer function, 1 is feedback
   
   T1 = feedback(G1, 1);
   % Check whether the system is stable (T1)
   pT1 = pole(T1)
  % figure(3);
   % Compare closed looop vs open loop system
   step(T1, G1);
   legend('T1 Closed Loop', 'G1 Open Loop');
   
  % Multiple step response for overdamped, underdamped, and critically
  % Damped systems
  
  K2 = 4;
  T2 = feedback(K2*G1, 1)
  pT2 = pole(T2)
  
  K3 = 12;
  T3 = feedback(K3*G1, 1)
  pT2 = pole(T3)
  
  figure(4)
  step(T1, T2, T3)
  legend('Overdamped K = 1 ', 'Critically damped K = 4 ', 'Underdamped K = 12');
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  