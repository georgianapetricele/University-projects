clear all;
clc;
clf;
n=input("Enter the number of trials: ");
p=input("Enter the probability of success: ");
k=0:n;
px=binopdf(k,n,p);
plot(k,px,"*");
hold on;

x=0:0.01:n;
fx=binocdf(x,n,p);
plot(x,fx,"--");
title("Pdf and Cdf")
legend("pdf","cdf")
hold off;
%disttool in command window for checking the graphs