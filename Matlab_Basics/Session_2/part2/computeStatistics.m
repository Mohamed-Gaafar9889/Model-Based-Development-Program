% Task 3: Function with Multiple Outputs
% 
% Create a function named computeStatistics that takes a vector of numbers as input.
% This function should return both the mean and the standard deviation of the input vector.
% Call the function with sample data and display the results.

function [mean , standard_deviation] = computeStatistics(varargin)
sum = 0;
for i = 1 :nargin
sum = sum + varargin{i};
end
mean = sum/nargin;
Sum2 = 0;
for i = 1 :nargin
element_Minus_mean =  varargin{i} - mean;
Sum2 = Sum2 + (element_Minus_mean)^2;

end

standard_deviation = sqrt(Sum2/nargin);

end