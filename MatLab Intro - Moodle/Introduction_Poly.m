%% Polynomial (double %% used for section within 1 script file)
clc; clear

% s^2+4*s+4
b = [1 4 4];

% s^3+7*s^2+12*s

c= [1 7 12 0];

% s^3+1
d = [1 0 0 1];

% Finding roots
r1 = roots(b)
r2 = roots(c)
r3 = roots(d)

%% Evaluating polynomial for a give value
% Poly value of b at 1
polyval(b, 1)

% Multiplying polynomials
D = conv(b,c)

% Dividing two polynomials (devide D by b, expect to get c)
[q, r] = deconv(D, b)

% Converting roots to polynomial(s)
e = [-2 -2]
p1 = poly(e)
p1 = poly(r2)
