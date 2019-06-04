'(ch2p7)' % Display label.
% 
% (page 773)


numf=[7 9 12]; % Define numerator of F(s).
denf=conv(poly([0 -7]),[1 10 100]); % Define denominator of F(s).
[K,p,k]=residue(numf,denf) % Find residues and assign to K; find roots of den 
