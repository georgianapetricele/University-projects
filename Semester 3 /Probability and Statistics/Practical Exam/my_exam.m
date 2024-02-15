
S = [4.6, 0.7, 4.2, 1.9, 4.8, 6.1, 4.7, 5.5, 5.4];
G = [2.5, 1.3, 2.0, 1.8, 2.7, 3.2, 3.0, 3.5, 3.4];

n1 = length(S);
n2 = length(G);

%significance level
alpha = 0.05;
fprintf("\na)\n");
fprintf("The null hypothesis H0: population variances are equal\n");
fprintf("The alternative hypothesis H1: population variances differ\n");
fprintf('We will perform a two-tailed test using vartest2\n\n');


% here we compute the fischer inverse distribution and we will use it for 
% the rejection region
tt1 = finv(alpha/2, n1-1, n2-1);
tt2 = finv(1-(alpha/2), n1-1, n2-1);

[h, p, ci, stats] = vartest2(S, G, alpha, 0);

s1 = var(S);
s2 = var(G);
fprintf("h is %d\n", h);
if h == 1
    type="unequal";
    fprintf("So the null hyphotesis is rejected. The populations differ.\n");
    fprintf('The sigmas are unequal!\n');
     c = (s1/n1) / ((s1/n1) + (s2/n2));
     n = ((c^2)/(n1-1) + ((1-c)^2)/(n2-1))^(-1);
    
else
    type="equal";
    fprintf("So the null hyphotesis is NOT rejected. The populations do not differ.\n");
    fprintf('The sigmas are equal!\n');
    n=n1+n2-2;
end


fprintf("The rejection region is (-Inf, %5.4f) U (%5.4f, Inf)\n", tt1, tt2);
fprintf("The value of the test statistic is %5.4f\n", stats.fstat);
fprintf("The P-value of the variances test is %5.4f\n", p);
fprintf("The value of H of the variances test is %.4f\n", H);
fprintf("The alternative Confidence Interval is (%5.4f, %5.4f)\n", ci(1), ci(2));


fprintf("\nb)\n")
fprintf('We have to find a 95 confidence interval for the difference of 2 population means\n')
fprintf('We need difference, sigma1 and sigma2 are different,unknown so we use 3rd formula from 3 in CI file\n')
 
tl = mean(S) - mean(G) - tinv(1-(alpha/2), n) * sqrt(s1/n1 + s2/n2);
tu = mean(S) - mean(G) + tinv(1-(alpha/2), n) * sqrt(s1/n1 + s2/n2);

fprintf("The %2.0f%% confidence interval for the difference of the average heat loses is (%5.4f, %5.4f)\n", 100 * (1-alpha), tl ,tu);
 
