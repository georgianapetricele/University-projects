%2.a.
clear all
clc

x1=[22.4,24.5,21.6,22.4,24.8,21.7,23.4,23.3,21.6,20.0];
x2=[17.7,19.6,12.1,15.4,14.0,14.8,19.6,14.8,12.6,12.2];

n1=length(x1);
n2=length(x2);
%formula 2  for q1-q2, q1=q2
conf_lev=input("Enter the conf level: ");
alpha=1-conf_lev; %alpha=significance level
%sigma=5;
%s=std(x) %standard deviation
mean_x1=mean(x1);
mean_x2=mean(x2);

v1=var(x1); %v1=s1^2
v2=var(x2); %variance

sp2=((n1-1)*v1+(n2-1)*v2)/n1+n2-2;
sp=sqrt(sp2);

quantile_1=tinv(1-alpha/2,n1+n2-2);
quantile_2=tinv(alpha/2,n1+n2-2);

tl=mean_x1-mean_x2-quantile_1*sp*sqrt((1/n1)+(1/n2));
tu=mean_x1-mean_x2+quantile_1*sp*sqrt((1/n1)+(1/n2));
fprintf("c) The %2.0f%% confidence interval for variance " + "for the mean is (%5.3f,%5.3f)\n"+ " ",(1-alpha)*100,tl,tu)
