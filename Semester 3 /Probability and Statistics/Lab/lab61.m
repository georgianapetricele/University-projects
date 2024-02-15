clc
clear all

x=[7;7;4;5;9;9;4;12;8;1;8;7;3;13;2;1;17;7;12;5;6;2;1;13;14;10;2;4;9;11;3;5;12;6;10;7];
n=length(x);
sigma=5;

alpha=input("Enter the significance level: ");
fprintf("Significance level alpha=%3.2f\n",alpha);

fprintf("Left-tailed test for the mean(sigma known)\n");
testvalueh0=8.5;
quantile_alpha=norminv(alpha,0,1);
tail=-1; %left-tailed test
[h,pvalue,confint,zval]=ztest(x,testvalueh0,sigma,alpha,tail);
fprintf("h is %d\n",h);
confint_correct=(1-alpha)*100;
if h==0
    fprintf("So the null hyphotesis is not rejected\n");
else
    fprintf("So the null hyphotesis is rejected\n");
end
fprintf("i.e the data suggests that the standard is NOT met\n");
fprintf("The rejection region is (-Inf,%7.4f)\n",quantile_alpha);
fprintf("The value of the test statistic TS is %7.4f\n",zval);

%b.
testvalueh02=5.5;
quantile_alpha=tinv(alpha,n-1);
tail2=1;
[h,pval2,ci,stats]=ttest(x,m,alpha,tail2);
fprintf("h is %d\n",h);
confint_correct=(1-alpha)*100;
if h==0
    fprintf("So the null hyphotesis is not rejected\n");
else
    fprintf("So the null hyphotesis is rejected\n");
end

fprintf("i.e the data suggests that the standard is NOT met\n");
fprintf("The rejection region is (-Inf,%7.4f)\n",quantile_alpha);
fprintf("The value of the test statistic TS is %7.4f\n",stats.tstat);


