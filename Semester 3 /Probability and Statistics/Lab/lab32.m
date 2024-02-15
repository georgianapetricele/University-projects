clear all;
clc;
clf;

p=99999
fprintf("The range of p is 0.005 and 0.95")
while p>=0.05 && p<=0.95
    p=input("Enter the probability of success: ");
end

for n=1:5:100
    k=0:n
    a=binopdf(k,n,p);
    b=normpdf(n*p,sqrt(n))
    title("n="+n);
    pause(0.5);
end