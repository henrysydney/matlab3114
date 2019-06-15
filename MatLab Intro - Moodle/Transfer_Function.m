%% Transfer Functions
clc; clear;
% Use vector of coefficients
% s^2+4*s+4 - nominator
   num1 = [1 4 4];

% s^3+7*s^2+12*s - denominator
   den1 = [1 7 12 0];

   G1 = tf(num1, den1)

% Create transfer function with zeros, poles and gain (zpk(z,p,k))
% Use vectors of root
% nominator has 2 roots (s+2)^2
z = [-2  -2]

% denominator has 3 roots s*(s-3)*(s-4)
p = [0 3 4]
G2 = zpk(z, p, 1)

% Create transfer function with the Laplace variable (s=tf('s'), G=1/(s+1))
% Define "s" as Laplace variable
   % s = zpk('s')
s = tf('s')

G3 = (s^2+4*s+4)/(s^3+7*s^2+12*s)

% G2 = zpk(z, p, 1)
G4 = ((s+2)^2)/(s*(s-3)*(s-4))