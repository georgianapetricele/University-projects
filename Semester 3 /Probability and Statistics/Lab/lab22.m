%Application
clear all;
clc;
clf;
n=3;
p=0.5;
k=0:n;
px=binopdf(k,n,p);
[k;px]  %the matrix of prob 2 row=what is the prob of obtaining 1 head, 2 ..