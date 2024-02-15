clc
clear all
x=[7;7;4;5;9;9;4;12;8;1;8;7;3;13;2;1;17;7;12;5;6;2;1;13;14;10;2;4;9;11;3;5;12;6;10;7];
n=length(x);

conf_lev=input("Enter the conf level: ");
alpha=1-conf_lev;
sigma=5;
mean_x=mean(x);
quantile_1=norminv(1-alpha/2); %0,1 default 
quantile_2=norminv(alpha/2);
tl=mean_x-sigma/sqrt(n)*quantile_1;
tu=mean_x-sigma/sqrt(n)*quantile_2;
fprintf("a) The %2.0f%% confidence interval " + "for the mean is (%5.3f,%5.3f)\n"+ " ",(1-alpha)*100,tl,tu)
