%% Pre-lab Exercise
   % clc; clear;
   close all;

% Loading data from PreLab1_Data.mat
   % load('./PreLab1_Data.mat');

% Q1- Storing data respect to time and speed
   time = discSpeed(:, 1);             % Store values of time from the 1st column of inputdata 
   speed = discSpeed(:, 2);            % Store values of speed from the 2nd column of inputdata 
   
   figure;
   plot(time, speed);
   grid ON;
   xlabel('Time (sec)');
   ylabel('Disc Speed (rpm)');
   title('1A: Measured Speed Data');

% Q2 - Truncating the data, 
   newDisc = discSpeed;                 % make a copy of input data
   time_remove = newDisc(:, 1) < 1;     % For which rows is column 1 less than 1
   newDisc(time_remove, :) = [];        % Remove those rows
   time1 = newDisc(:, 1) - 1;           % Shifting the time
   speed1 = newDisc(:, 2);                
   
   figure;
   plot(time1, speed1);
   xlim([0 10])
   grid ON;
   xlabel('Time (sec)');
   ylabel('Disc Speed (rpm)');
   title('1B: Truncated Speed Data');
 
% Q3 - DC Offset removal
   time3 = time1;
   speed3 = speed1;
   
   a = speed3(1:1000,1);                  % Storing data of the 1st second
   lowest = min(a(:));                    
   highest = max(a(:));
   m = (lowest+highest)/2;                % Find average of highest and lowest of the 1st secondd
   
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
   newDisc4 = discSpeed;                  % make a copy of input data
   time_remove4 = newDisc4(:, 1) < 2;     % For which rows is column 1 less than 2
   newDisc4(time_remove4, :) = [];        % Remove those rows
   time4 = newDisc4(:, 1) - 2;            % Shifting the time
   speed4 = newDisc4(:, 2);
   speed4 = newDisc4(:, 2) - m;


   figure;
   plot(time4, speed4);
   xlim([0 10])
   ylim([0 600])
   grid ON;
   xlabel('Time (sec)');
   ylabel('Disc Speed (rpm)');
   title('1C: Offset-free Speed Data');

% Q5 - Design a simple Low Pass Filter
   % N=4001;
   % fs=6000;
   % n=0:N-1;
   % F=fft(discSpeed);
   % f=n/N*fs;
   % L = 1:length(discSpeed)/2+1;
   % plot(f,abs(F(1:length(discSpeed)/2+1))); 
   % xlim([0 200]);       

   