clc
clear all


x =20;
y = 30;
Cell_Array = {55 , 22 , 36 , 'This is a cell array' , x ,y };
for i =size(Cell_Array , 2): -1: 1
    disp(Cell_Array{i})
end