% Task 4: Nested Functions
% 
% Create a main function called outerFunction.
% Inside outerFunction, define another function called innerFunction.
% innerFunction should take two inputs, add them, and return the result.
% Call innerFunction from outerFunction and display the result.

function output = outerFunction(varargin)

function result = innerFunction (a,b)
    result = a+b;
end
output = innerFunction(varargin{1} , varargin{2});
end