% 3. Nickel powders are used in coatings used to shield electronic equipment.
%A random sample is selected, and the sizes of nickel particles in each coating
% are recorded (they are assumed to be approximately normally distributed):
%3.26, 1.89, 2.42, 2.03, 3.07, 2.95, 1.39, 3.06, 2.46, 3.35, 1.56, 1.79, 1.76, 3.82, 2.42, 2.96
%a. Find a 95% confidence interval for the average size of nickel particles.

clc
clear all
x=[3.26, 1.89, 2.42, 2.03, 3.07, 2.95, 1.39, 3.06, 2.46, 3.35, 1.56, 1.79, 1.76, 3.82, 2.42, 2.96];
n=length(x);

%conf_lev=input("Enter the conf level: ");
conf_lev=0.95;
alpha=1-conf_lev;

s=std(x); %standard deviation
mean_x=mean(x);
quantile_1=tinv(1-alpha/2,n-1);
quantile_2=tinv(alpha/2,n-1);
tl=mean_x-s/sqrt(n)*quantile_1;
tu=mean_x-s/sqrt(n)*quantile_2;
fprintf("a) The %2.0f%% confidence interval " + "for the mean is (%5.3f,%5.3f)\n"+ " ",(1-alpha)*100,tl,tu)

%b.At the 1% significance level, on average, do these nickel particles seem to be smaller than 3?

%alpha=input("Enter the significance level: ");
alpha=0.01;
%fprintf("Significance level alpha=%3.2f\n",alpha);

fprintf("Left-tailed test for the mean(sigma unknown)\n");
testvalueh02=3; %smaller =>left test
quantile_alpha=tinv(alpha,n-1);
tail2=-1;
[h,pval2,ci,stats]=ttest(x,testvalueh02,alpha,tail2);
fprintf("h is %d\n",h);
confint_correct=(1-alpha)*100;
if h==0
    fprintf("So the null hyphotesis is not rejected.Nickel particles are NOT smaller than 3.\n");
else
    fprintf("So the null hyphotesis is rejected.Nickel particles are smaller than 3.\n");
end

%fprintf("i.e the data suggests that the standard is NOT met\n");
fprintf("The rejection region is (-Inf,%7.4f)\n",quantile_alpha);
fprintf("The confidence interval is (%4.4f,%4.4f).\n",ci)
fprintf("The value of the test statistic TS is %7.4f\n",stats.tstat);
fprintf("The P-value for the variances test is %6.4f.\n",pval2);


%c) Find a 99% confidence interval for the standard deviation of the size of nickel particles.
% We need to find a 95% confidence interval, so the significal level(alpha) will
% be 100(1-alpha)=99, alpha = 0.01

%conf_lev=input("Enter the conf level: "); %conf)lev=1-sign_lev
conf_lev=0.99;
alpha=1-conf_lev; %alpha=0.01
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


