%% Lab exercise 02

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
  
% As the value of Fit2 > Fit1; thus, Manufacture Model performs better than the Indentified Model

%% A mass (Ring) is attached
clear all; close all; clc;

% Import require data
 run 'ELEC3114_Lab2.m';
 load 'speed_with_ring.mat';

% Assign value
%  timeValue = Speed(:, 1);
    newDisc = Speed;                  % make a copy of input data

% As we prefer to use Manufacture Mode, 
%  Yact = Speed(:, 3);    % Actual speed (Yact)
%  Yman = Speed(:, 5);    % Speed is filter - Manufacture Model

% Truncated & offset data
% Trunacating the first second to find the offset

    time_remove = newDisc(:, 1) < 1;     % For which rows is column 1 less than 1
    newDisc(time_remove, :) = [];        % Remove those rows
    time1 = newDisc(:, 1) - 1;           % Shifting the time
    speed1 = newDisc(:, 5);   
    a = speed1(1:1000,1);                  % Storing data of the 1st second
    lowest = min(a(:));                    
    highest = max(a(:));
    m = (lowest+highest)/2;                % Find average of highest and lowest of the 1st secondd

   newDisc1 = Speed;
   time_remove4 = newDisc1(:, 1) < 2;     % For which rows is column 1 less than 2
   newDisc1(time_remove4, :) = [];        % Remove those rows
   time4 = newDisc1(:, 1) - 2;            % Shifting the time
   speed4 = newDisc1(:, 5);
   speed4 = newDisc1(:, 5) - m;


   figure;
   plot(time4, speed4);
   xlim([0 10])
   ylim([0 600])
   grid ON;
   xlabel('Time (sec)');
   ylabel('Disc Speed (rpm)');
   title('Offset-free Speed Data');


