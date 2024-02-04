% Lab1: Task 1 , while loop
count = 2;
fprintf('Even Numbers between 2 and 20 are : ');
while count <= 20
    if rem(count , 2) ==0   
        fprintf('%d \n',count);
    end
    count = count + 1 ;
end

Input_User  = input('enter your number to gt the factorial for it : ');
factorial = 1;
for counter = Input_User : -1 :1
    factorial = factorial * counter;
end
fprintf ('Factorial of %d is : %d \n', Input_User , factorial);