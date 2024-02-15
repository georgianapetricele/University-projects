%s2-variance!!! not std^2
%s=standard deviation of the sample

%c.a.b.
clc
clear all
x=[7;7;4;5;9;9;4;12;8;1;8;7;3;13;2;1;17;7;12;5;6;2;1;13;14;10;2;4;9;11;3;5;12;6;10;7];
n=length(x);

%conf_lev=input("Enter the conf level: ");
alpha=1-conf_lev;
%sigma=5;
s=std(x) %standard deviation
mean_x=mean(x);
s2=var(x) %variance
quantile_1=chi2inv(1-alpha/2,n-1);
quantile_2=chi2inv(alpha/2,n-1);
tl=(n-1)*s2/quantile_1;
tu=(n-1)*s2/quantile_2;
fprintf("c) The %2.0f%% confidence interval for variance " + "for the mean is (%5.3f,%5.3f)\n"+ " ",(1-alpha)*100,tl,tu)
fprintf("c) The %2.0f%% confidence interval for standard deviation " + "for the mean is (%5.3f,%5.3f)\n"+ " ",(1-alpha)*100,sqrt(tl),sqrt(tu))