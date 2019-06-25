% Lab exercise 02

% Data is stored in discSpeed
    
% Pull out timeValue
  timeValue = discSpeed(:,1 );

% Pull out data for Actual Speed (Yact), Identified Speed (Yiden),
% Manufacture Speed (Yman)
  Yact = discSpeed(:, 3);
  Yiden = discSpeed(:, 4);
  Yman = discSpeed(:, 5);
  
% Finding fit value
% Fit1 = Actual data Yact vs. Identified Speed (Yiden)
  Fit1 = (1 - norm(Yact - Yiden)/norm(Yact - mean(Yact)))*100  
% Fit2 = Acutal data Yact vs. Manufacture Speed (Yman)
  Fit2 = (1 - norm(Yact - Yman)/norm(Yact - mean(Yact)))*100
  
% As the value of Fit2 > Fit1, there fore Identified Function performs
% better
