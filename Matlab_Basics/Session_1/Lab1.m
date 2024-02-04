%% 
% Create a 3x3 matrix named matrixA with the following values:
% 
% 1 2 3
% 
% 4 5 6
% 
% 7 8 9
% 
% Create a 3x3 matrix named matrixB with the following values:
% 
% 10 11 12
% 
% 13 14 15
% 
% 16 17 18
% 
% Calculate the sum of matrixA and matrixB and store it in a variable called 
% matrixSum.
% 
% Display the contents of matrixSum

clear all ;
clc;
matrixA = [1 2 3 ;4 5 6 ;7 8 9];
matrixB = [10 11 12 ; 13 14 15 ; 16 17 18];
matrixSum = matrixA + matrixB ;
matrixSum
%% 
% Part 2: Matrix Concatenation
% 
% Create a row vector named rowVector with values from 1 to 5.
% 
% Create a column vector named columnVector with values from 6 to 10.
% 
% Concatenate rowVector and columnVector horizontally and store the result in 
% a variable called horizontalConcat.
% 
% Display the contents of horizontalConcat

rowVector = 1 : 5;
columnVector = (colon (6,10))';
horizontalConcat = horzcat (rowVector , columnVector.' )
%% 
% Using repmat Function
% 
% Create a 2x2 matrix named originalMatrix with any values you like.
% 
% Use the repmat function to replicate originalMatrix into a 4x4 pattern and 
% store it in a variable called repeatedMatrix.
% 
% Display the contents of repeatedMatrix

originalMatrix = [5 10 ; 20 30];
repeatedMatrix = repmat(originalMatrix,2,2);
repeatedMatrix
%% 
% Challenge yourself by performing the following tasks:
% 
% Create a 3x3 identity matrix (a matrix with diagonal elements as 1 and others 
% as 0) and store it in a variable called identityMatrix.
% 
% Perform matrix multiplication between identityMatrix and matrixA. Store the 
% result in a variable called matrixProduct.
% 
% Display the contents of matrixProduct.

identityMatrix = eye(3);
matrixProduct = identityMatrix .* matrixA  
