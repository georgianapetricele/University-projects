clear all;
clc;

X = [1001.7, 975.0, 978.3, 988.3, 978.7, 988.9, 1000.3, 979.2, 968.9, 983.5, 999.2, 985.6];

n = length(X);

alpha = 0.05;

tta = tinv(1-alpha, n-1);

[h,p,ci,stats] = ttest(X, 995, alpha, 1);

fprintf("\na)\n\n")

fprintf("h is %d\n", h);
if h == 1
    fprintf("So the hyphotesis is rejected. Muzzle is faster than 995.\n");
else
    fprintf("So the hyphotesis is NOT rejected. Muzzle is NOT faster than 995.\n");
end
fprintf("The rejection region is (%5.4f, Inf)\n", tta);
fprintf("The Confidence Interval is (%f, %f)\n", ci(1), ci(2));
fprintf("The value of the test statistic is %5.4f\n", stats.tstat);
fprintf("P value is %5.7f\n", p);


confLevel = 0.99;

s2=var(X) %variance
quantile_1=chi2inv(1-alpha/2,n-1);
quantile_2=chi2inv(alpha/2,n-1);
tl=(n-1)*s2/quantile_1;
tu=(n-1)*s2/quantile_2;
fprintf("c) The %2.0f%% confidence interval for variance " + "for the mean is (%5.3f,%5.3f)\n"+ " ",confLevel*100,tl,tu)
fprintf("c) The %2.0f%% confidence interval for standard deviation " + "for the mean is (%5.3f,%5.3f)\n"+ " ",confLevel*100,sqrt(tl),sqrt(tu))








