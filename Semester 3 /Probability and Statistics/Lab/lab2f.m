%Application f.
clear all;
clc;
clf;
n=3;
p=0.5;
s=input("Enter the nr of times to run the experiment: ");
var=rand(3,s);
var<0.5;
hist(sum(rand(n,s)>0.5))