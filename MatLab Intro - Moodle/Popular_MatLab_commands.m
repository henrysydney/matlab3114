Index: MATLAB Commands List
%http://ctms.engin.umich.edu/CTMS/index.php?aux=Index_Commands
Following is a list of commands used in the Control Tutorials for MATLAB and Simulink. Use help in MATLAB for more information on how to use any of these commands.

In these tutorials, we use commands/functions from MATLAB, from the Control Systems Toolbox, as well as some functions which we wrote ourselves. For those functions which are not standard in MATLAB, we give links to their descriptions. For more information on writing MATLAB functions, see the function page.

Command	Description
abs         Absolute value
acker       Compute the K matrix to place the poles of A-BK, see also place
axis        Set the scale of the current plot, see also plot, figure
bode        Draw the Bode plot, see also logspace, margin, nyquist1
c2d         Continuous system to discrete system
clf         Clear figure
conv        Convolution (useful for multiplying polynomials), see also deconv
ctrb        The controllability matrix, see also obsv
deconv      Deconvolution and polynomial division, see also conv
det         Find the determinant of a matrix
dlqr        Linear-quadratic regulator design for discrete-time systems, see also lqr
eig         Compute the eigenvalues of a matrix
eps	MATLAB's numerical      tolerance
feedback	Connect linear systems in a feedback loop
figure      Create a new figure or redefine the current figure, see also subplot, axis
for         For loop
format      Number format (significant digits, exponents)
function	Creates function m-files
grid        Draw the grid lines on the current plot
gtext       Add a piece of text to the current plot, see also text
help        Matlab help documentation
hold        Hold the current graph, see also figure
if	Conditionally execute statements
imag        Returns the imaginary part of a complex number, see also real
impulse     Impulse response of linear systems, see also step, lsim
input       Prompt for user input
inv         Find the inverse of a matrix
legend      Graph legend
length      Length of a vector, see also size
linspace	Returns a linearly spaced vector
lnyquist	Produce a Nyquist plot on a logarithmic scale, see also nyquist1
log         Natural logarithm, also log10: common logarithm
loglog      Plot using log-log scale, also semilogx/semilogy
logspace	Returns a logarithmically spaced vector
lqr         Linear quadratic regulator design for continuous systems, see also dlqr
lsim        Simulate a linear system, see also step, impulse
margin      Returns the gain margin, phase margin, and crossover frequencies, see also bode
minreal	Produces a minimal realization of a system (forces pole/zero cancellations)
norm	Norm of a vector
nyquist1	Draw the Nyquist plot, see also lnyquist. Note this command was written to replace the MATLAB standard command nyquist to get more accurate Nyquist plots.
obsv	The observability matrix, see also ctrb
ones	Returns a vector or matrix of ones, see also zeros
place	Compute the K matrix to place the poles of A-BK, see also acker
plot	Draw a plot, see also figure, axis, subplot.
poly	Returns the characteristic polynomial
polyval	Polynomial evaluation
print	Print the current plot (to a printer or postscript file)
pzmap	Pole-zero map of linear systems
rank	Find the number of linearly independent rows or columns of a matrix
real	Returns the real part of a complex number, see also imag
rlocfind	Find the value of k and the poles at the selected point
rlocus	Draw the root locus
roots	Find the roots of a polynomial
rscale	Find the scale factor for a full-state feedback system
set	Set(gca,'Xtick',xticks,'Ytick',yticks) to control the number and spacing of tick marks on the axes
sgrid	Generate grid lines of constant damping ratio (zeta) and natural frequency (Wn), see also sigrid, zgrid
size	Gives the dimension of a vector or matrix, see also length
sqrt	Square root
ss	Create state-space models or convert LTI model to state space, see also tf
ssdata	Access to state-space data. See also tfdata
stairs	Stairstep plot for discrete response
step	Plot the step response, see also impulse, lsim
subplot	Divide the plot window up into pieces, see also plot, figure
text	Add a piece of text to the current plot, see also title, xlabel, ylabel, gtext
tf	Creation of transfer functions or conversion to transfer function, see also ss
tfdata	Access to transfer function data, see also ssdata
title	Add a title to the current plot
wbw	Returns the bandwidth frequency given the damping ratio and the rise or settling time.
xlabel/ylabel	Add a label to the horizontal/vertical axis of the current plot, see also title, text, gtext
zeros	Returns a vector or matrix of zeros
zgrid	Generates grid lines of constant damping ratio (zeta) and natural frequency (Wn), see also sgrid, sigrid