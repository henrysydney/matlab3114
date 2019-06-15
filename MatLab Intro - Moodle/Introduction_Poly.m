%http://ctms.engin.umich.edu/
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
   roots(D)
% Dividing two polynomials (devide D by b, expect to get c)
   [q, r] = deconv(D, b);

% Converting roots to polynomial(s)
   e = [-2 -2];
   p1 = poly(e);
   p1 = poly(r2);

   f = [0 -3 -4];
   p2 = poly(f);

   g = [-1+2*j -1-2*j];
   p3 = poly(g)

%% Partial Fraction expansion
   [R, P, K] = residue([1 4 4],[1 7 12 0]);

   %1/s*(s^2+2*s+5)
   G = tf(1, [1 2 5 0])
   [R,P,K] = residue(1, [1 2 5 0])

   % help laplace


