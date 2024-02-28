% Create time vector
time = [0:50]';  % Time from 0 to 30 seconds

% Initialize value vector
value = zeros(size(time));

% Set value from 0 to 0.6 (0 to 15 seconds)
value(1:15) = linspace(0, 0.6, 15);

% Set value from 0.6 to 0.3 (301 to 600 seconds)
value(16:24) = linspace(0.6, 0.29, 9);

value(24:33) = linspace(0.29, 0.6, 10);

value(34:41) = linspace(0.6, 0.29, 8);

value(41:51) = linspace(0.29, 0.6, 11);
% Create a timeseries object
myTimeSeries = timeseries(value, time);

% Display the time series
plot(myTimeSeries);
