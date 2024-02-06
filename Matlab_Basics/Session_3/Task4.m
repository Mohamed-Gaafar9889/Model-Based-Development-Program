clc
clear all

user_input = input ('Enter a number to be checked whether it is odd or even :');
if rem(user_input , 2) ==0
    fprintf('%d is even\n' , user_input);
else
    fprintf('%d is odd\n' , user_input);
end