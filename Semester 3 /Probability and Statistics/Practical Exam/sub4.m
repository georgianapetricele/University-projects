%A study is conducted to compare heat loss in glass pipes, versus steel pipes of the same size. Various liquids
%at identical starting temperatures are run through segments of each type and the heat loss (in Co) is measured.
%These data result (normality of the two populations is assumed):
%Steel 4.6 0.7 4.2 1.9 4.8 6.1 4.7 5.5 5.4
%Glass 2.5 1.3 2.0 1.8 2.7 3.2 3.0 3.5 3.4
%a. At the 5% significance level, do the population variances seem to differ?

S = [4.6, 0.7, 4.2, 1.9, 4.8, 6.1, 4.7, 5.5, 5.4];
G = [2.5, 1.3, 2.0, 1.8, 2.7, 3.2, 3.0, 3.5, 3.4];

n1 = length(S);
n2 = length(G);

%significance level
alpha = 0.05;

tt1 = finv(alpha/2, n1-1, n2-1);
tt2 = finv(1-(alpha/2), n1-1, n2-1);

[h, p, ci, stats] = vartest2(S, G, alpha, 0);

fprintf("\na)\n");

fprintf("h is %d\n", h);
if h == 1
    type="unequal";
    fprintf("So the hyphotesis is rejected. The populations differ.\n");
     c = (s1/n1) / ((s1/n1) + (s2/n2));
     n = ((c^2)/(n1-1) + ((1-c)^2)/(n2-1))^(-1);
    
else
    type="equal";
    fprintf("So the hyphotesis is NOT rejected. The populations do not differ.\n");
    n=n1+n2-2;
end


fprintf("The rejection region is (-Inf, %5.4f) U (%5.4f, Inf)\n", tt1, tt2);
fprintf("The Confidence Interval is (%5.4f, %5.4f)\n", ci(1), ci(2));
fprintf("The value of the test statistic is %5.4f\n", stats.fstat);
fprintf("P value is %5.4f\n\n", p);


%b. At the same significance level, does it seem that on average, steel pipes lose more heat than glass pipes?
%The null hyp. is H0: m1 = m2 (the standard is met)
%The alternative hyp. is H1: m1 > m2(the standard is not met) 
fprintf("\nb)\n");

[h, p, ci, stats] = ttest2(S, G, alpha, "right", type);

 s1 = var(S);
 s2 = var(G);

rr = tinv(1-alpha, n);

fprintf("h is %d\n", h);
if h == 1
    fprintf("So the hyphotesis is rejected. Steel pipes lose more heat on average.\n");
else
    fprintf("So the hyphotesis is NOT rejected. Glass pipes lose more heat on average.\n");
end
fprintf("The rejection region is (%5.4f, Inf)\n", rr);
fprintf("The Confidence Interval is (%5.4f, %5.4f)\n", ci(1), ci(2));
fprintf("The value of the test statistic is %5.4f\n", stats.tstat);
fprintf("P value is %5.4f\n", p);
