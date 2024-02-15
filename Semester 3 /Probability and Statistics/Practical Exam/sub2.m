% A food store owner receives 1-liter water bottles from two suppliers. After some
%complaints from customers, he wants to check the accuracy of the weights of 1-liter water bottles.
% He finds the following weights (the two populations are approximately normally distributed):
%Supplier A 1021 980 1017 988 1005 998 1014 985 995 1004 1030 1015 995 1023
%Supplier B 1070 970 993 1070 970 993 1013 1006 1002 1014 997 1002 1010 975
%a. At the 5% significance level, do the population variances seem to differ?

clear all;
clc;

A = [1021, 980, 1017, 988, 1005, 998, 1014, 985, 995, 1004, 1030, 1015, 995, 1023];
B = [1070, 970, 993, 1013, 1006, 1002, 1014, 997, 1002, 1010, 975];
n1 = length(A);
n2 = length(B);

%significance lvl
alpha=0.05;

%The null hyp. is H0: m1 = m2 (the standard is met)
%The alternative hyp. is H1: m1 != m2(the standard is not met)
%We use two tailed test

tt1 = finv(alpha/2, n1-1, n2-1);
tt2 = finv(1-(alpha/2), n1-1, n2-1);
%quantiles for the rejection region of the two tailed test

[h, pval, ci, zvalue] = vartest2(A, B, alpha, 0);
fprintf("a).\nh is: %d\n",h)
if h == 0
  fprintf("The null hypothesis is not rejected, the population variances seem to be equal\n")
else
	fprintf("The null hypothesis is rejected, the population variances seem to differ\n")
end

fprintf('The rejection region for F is (-Inf, %6.4f) U (%6.4f, Inf)\n', tt1, tt2)
fprintf('The value of the test statistic F is %6.4f\n', zvalue.fstat)
fprintf('The P-value for the variances test is %6.4f\n', pval)
fprintf("The confidence interval is (%4.3f, %4.3f)\n", ci);


%At the same seg. level, on average, does Supplier A seem to be more reliable?
%We perfom a ttest2 (two sample t test)
%The null hyp. is H0: no significant difference in the average reliability of Supplier A and Supplier B
%The alternative hyp is H1: Supplier A seems to be more reliable on average compared to Supplier B.

fprintf("\nb)\n");

%equal if get at a) not differ
[h, p, ci, stats] = ttest2(A, B, alpha, "right", "equal");

rr = tinv(1-alpha, n1+n2-2);

fprintf("h is %d\n", h);
if h == 1
    fprintf("So the hyphotesis is rejected. Supplier A seems to be more reliable.\n");
else
    fprintf("So the hyphotesis is NOT rejected. Supplier A seems to NOT be more reliable.\n");
end
fprintf("The rejection region is (%5.4f, Inf)\n", rr);
fprintf("The Confidence Interval is (%f, %f)\n", ci(1), ci(2));
fprintf("The value of the test statistic is %5.4f\n", stats.tstat);
fprintf("P value is %5.4f\n", p);

