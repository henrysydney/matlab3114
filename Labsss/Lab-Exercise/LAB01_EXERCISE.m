% Lab 01 Exercise
clc; clear all; close all;
%    syms R Km B J L Ka;
% % Declare variables
   R = 1;
   Km = 5;
   B = 20;
   J = 1;
   L = 1*10^-3;
   H = 1;


% Find the tranfer function G(s) and its zeros, poles, and DC gain
   s = tf('s');
   G = Km/(s*(J*s+B)*(L*s+R));
   
   Z = zero(G);  %Zeros of G(s)
   P = pole(G);  %Poles of G(s)
   DCgain = dcgain(G); %DC gain of G(s)

% The unit step response
   f1 = figure;
   [y,t] = step(G);
   plot(t,y);
   grid on;
   title("Step Response");
   xlim([0 3]);
   xlabel("Time (seconds)");
   ylabel("Amplitude (rad)");

% CLosed loop system
   %G is transfer function, H(s) = 1 is feedback 
   Rs = 5.73*pi/180;    % 5.73 degress to rad
   Ka1 = 10;
   T1 = feedback(Ka1*G, H);
   pT1 = pole(T1);
   zT1 = zero(T1);
   Ka2 = 19.8;
   T2 = feedback(Ka2*G, H);
   pT2 = pole(T2);
   zT2 = zero(T2);
   Ka3 = 40;
   T3 = feedback(Ka3*G,H);
   pT3 = pole(T3);
   zT3 = zero(T3);

   figure
   step(Rs*T1, Rs*T2, Rs*T3)  %Scaled step response
   % set(0, 'DefaultLineWidth', 2);
   % set(0, 'DefaultLineLineWidth', 2);
   legend('Ka1 = 10', 'Ka2 = 19.8', 'Ka3 = 40')
   title('Set-point Response of Disc Drive System');
   xlabel('Time (s)');
   ylabel('Reader Head Position (rad)');
   set(gca,'color',[136/255 144/255 145/255])
   grid ON
   