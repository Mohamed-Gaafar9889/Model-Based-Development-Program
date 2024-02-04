%Task#2 : Switch Statement
Mode_of_Transportation = 'car';
N_miles = input ('the miles U took :');
switch Mode_of_Transportation
    case 'car'
        cost = 2.0 * N_miles + 200;
    case 'bus'
        cost = 1.5 * N_miles + 200;;
    case 'train'
        cost = 1.0 * N_miles + 200;;
    otherwise
        disp ('The mode entered is not available ');

end
fprintf ('Total Cost is %d \n',cost);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Question 2
code_color = input ('Enter the code of the color u need to search :');
switch code_color
    case 1
        fprintf('the Color oc the code %d is : white\n',code_color);
    case 2
        fprintf('the Color oc the code %d is : blue\n',code_color);
    case 3
        fprintf('the Color oc the code %d is : red\n',code_color);
    case 4
        fprintf('the Color oc the code %d is : orange\n',code_color);
    case 5
        fprintf('the Color oc the code %d is : black\n',code_color);
    otherwise
        fprintf('the code entered is not listed\n');
end
