% Create time vector
time = [0:30]';  % Time from 0 to 30 seconds

% Initialize value vector
value = zeros(size(time));

% Set value from 0 to 0.6 (0 to 300 seconds)
value(1:15) = linspace(0, 0.6, 15);

% Set value from 0.6 to 0 (301 to 600 seconds)
value(16:end) = linspace(0.6, 0, 16);

% Create a timeseries object
myTimeSeries = timeseries(value, time);

% Display the time series
disp(myTimeSeries);
