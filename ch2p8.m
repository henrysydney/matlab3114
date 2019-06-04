'(ch2p8) Example 2.3'           % Display label.
numy=32;                        % Define numerator.
% deny=poly([0 -4 -8]);           % Define denominator.
deny=conv(poly([0]), [1 12 32]);
[r,p,k]=residue(numy,deny)      % Calculate residues, poles, and
                                % direct quotient.