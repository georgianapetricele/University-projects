clear all;
clc;


%bernoulli model
p=input("Please enter the probability of success: ")
while p<=0 || p>=1
    p=input("Please enter the probability of success: ")
end

s=input("Enter how many simulations do you want to create: ")
while s<1
    s=input("Enter how many simulations do you want to create: ")
end

u=rand(1,s)
x=u<p
u_x=unique(x)
n_x=hist(x,length(u_x))  
[u_x;n_x]  %fail nr fail succ nr succ

rel_freq=n_x/s
[u_x;rel_freq]