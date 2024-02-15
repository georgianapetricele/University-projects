%Application
clear all;
clc;
clf;
n=3;
p=0.5;
c1=binopdf(0,n,p); %p(x=0)
c2=1-c1; %p(x !=1)
d1=binocdf(2,n,p); %p(x<=2)
d2=d1-binopdf(2,n,p); %p(x<2)
e1=1-(binocdf(1,n,p)-binopdf(1,n,p)); %p(x>=1)
e2=1-binocdf(1,n,p) %p(x>1)