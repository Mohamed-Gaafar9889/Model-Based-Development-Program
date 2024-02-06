

clc
clear

x = linspace (-2 *pi , 2 * pi , 100);
y = sin(x);

plot(x,y,'LineStyle','-','Color','b','LineWidth', 1 ,'Marker','*' , 'MarkerSize',1);


legend("Sin(x)");
xlabel("x");
ylabel("y");
title("Sine wave of x");