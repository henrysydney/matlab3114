%% Pre-lab Exercise
   clc; clear; close all;

% Loading data from PreLab1_Data.mat
   load('./PreLab1_Data.mat');

% Q1- Storing data respect to time and speed
   time = discSpeed(:, 1);
   speed = discSpeed(:, 2);
   
   figure;
   plot(time, speed);
   grid ON;
   xlabel('Time (sec)');
   ylabel('Disc Speed (rpm)');
   title('1A: Measured Speed Data');

% Q2 - Truncating the data, 
   % For which rows is column 1 less than 1
   newDisc = discSpeed;  
   time_remove = newDisc(:, 1) < 1; 
   % Remove those rows
   newDisc(time_remove, :) = [];
   time1 = newDisc(:, 1) - 1;
   speed1 = newDisc(:, 2);
   
   figure;
   plot(time1, speed1);
   xlim([0 10])
   grid ON;
   xlabel('Time (sec)');
   ylabel('Disc Speed (rpm)');
   title('1B: Truncated Speed Data');
 
% Q3 - DC Offset removal
   time3 = newDisc(:, 1) - 1;
   speed3 = newDisc(:, 2);
   m = mean(speed3)/2;
   speed3 = newDisc(:, 2) - m;
   figure;
   plot(time3, speed3);
   xlim([0 10])
   ylim([0 600])
   grid ON;
   xlabel('Time (sec)');
   ylabel('Disc Speed (rpm)');
   title('1C: Offset-free Speed Data');
   
% Q4 - Truncated Offset-free Speed Data
   newDisc4 = discSpeed;  
   time_remove4 = newDisc4(:, 1) < 2; 
   newDisc4(time_remove4, :) = [];
   time4 = newDisc4(:, 1) - 2;
   speed4 = newDisc4(:, 2);
   m = mean(speed4)/2;
   speed4 = newDisc4(:, 2) - m;


   figure;
   plot(time4, speed4);
   xlim([0 10])
   ylim([0 600])
   grid ON;
   xlabel('Time (sec)');
   ylabel('Disc Speed (rpm)');
   title('1C: Offset-free Speed Data');

   