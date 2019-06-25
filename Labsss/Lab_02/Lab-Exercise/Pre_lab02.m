% Pre-Lab Exercise 02
   clc; clear all; close all;
% Loading parameters 
   run 'ELEC3114_Lab2.m'   %Loading parameters' values from Moodle file
   s = tf('s');      % Declare transfer function

% DC Motor 'w(s)', 2nd order transfer function, Eq.2-2
   G = Km/((Jeq*Lm*s^2) + (Jeq*Rm*s) + (Km*Kb));
   poleG = pole(G);
   zeroG = zero(G);
   dcGainG = dcgain(G);

% DC Motor 'w(s)', 1st order simplified transfer function, Eq.2-3
   P = (Km/Rm)/((Jeq*s) + (Km*Kb)/Rm);
   poleP = pole(P);
   zeroP = zero(P);
   dcGainP = dcgain(P);

% Simulateing and Ploting the Speed Response
   [y,t]=step(3*G);
   figure(1)
   plot(t,30/pi*y,'r','Marker','>','linewidth',1);
   hold on

   [y1,t1]=step(3*P);
   plot(t1,30/pi*y1,'b','Marker','*','linewidth',1);
   title('Speed Response of DC motor');

   legend('2nd Order', '1st Order');
   set(get(gca, 'YLabel'), 'String', 'Disc Speed (rpm)');
   set(get(gca, 'XLabel'), 'String', 'Time (sec)');
   ylim([0 800]);
   grid ON
   hold off