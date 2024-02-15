% To reach the maximum efficiency in performing an assembling operation in a manufacturing plant,
%new employees are required to take a 1-month training course. A new method was suggested, and the manager
%wants to compare the new method with the standard one, by looking at the lengths of time required for employees
% to assemble a certain device. They are given below (and assumed approximately normally distributed):
%Standard 46 37 39 48 47 44 35 31 44 37
%New 35 33 31 35 34 30 27 32 31 31
%a. At the 5% significance level, do the population variances seem to differ?

clear all;
clc;

S = [46, 37, 39, 48, 47, 44, 35, 31, 44, 37];
N = [35, 33, 31, 35 ,34, 30, 27, 32, 31, 31];

n1 = length(S);
n2 = length(N);

%significance level
alpha = 0.05;

tt1 = finv(alpha/2, n1-1, n2-1);
tt2 = finv(1-(alpha/2), n1-1, n2-1);

[h, p, ci, stats] = vartest2(S, N, alpha, 0);

fprintf("\na)\n");

fprintf("h is %d\n", h);
if h == 1
    fprintf("So the hyphotesis is rejected. The populations differ.\n");
else
    fprintf("So the hyphotesis is NOT rejected. The populations do not differ.\n");
end
fprintf("The rejection region is (-Inf, %5.4f) U (%5.4f, Inf)\n", tt1, tt2);
fprintf("The Confidence Interval is (%5.4f, %5.4f)\n", ci(1), ci(2));
fprintf("The value of the test statistic is %5.4f\n", stats.fstat);
fprintf("P value is %5.4f\n\n", p);

fprintf("\nb)\n");
%b. Find a 95% confidence interval for the difference of the average assembling times.
%We need difference, sigma1 and sigma2 are unknown so we use 3rd formula from 3 in CI file

s1 = var(S);
s2 = var(N);

c = (s1/n1) / ((s1/n1) + (s2/n2));
n = ((c^2)/(n1-1) + ((1-c)^2)/(n2-1))^(-1);
 
tl = mean(S) - mean(N) - tinv(1-(alpha/2), n) * sqrt(s1/n1 + s2/n2);
tu = mean(S) - mean(N) + tinv(1-(alpha/2), n) * sqrt(s1/n1 + s2/n2);

fprintf("The %2.0f%% confidence interval for the difference of the average assembling times is (%5.3f, %5.3f)\n", 100 * (1-alpha), tl ,tu);
 
