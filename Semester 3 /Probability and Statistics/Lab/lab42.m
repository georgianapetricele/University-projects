clear all;
clc;


%binomial model

n=input("Please enter the nr of trials: ")
while n<1
    n=input("Please enter the nr of trials: ")
end

p=input("Please enter the probability of success: ")
while p<=0 || p>=1
    p=input("Please enter the probability of success: ")
end

s=input("Enter how many simulations do you want to create: ")
while s<1
    s=input("Enter how many simulations do you want to create: ")
end

u=rand(n,s)
m=u<p
x=sum(m)
u_x=unique(x)
n_x=hist(x,length(u_x))  
[u_x;n_x]  %fail nr fail succ nr succ

rel_freq=n_x/s
[u_x;rel_freq]

hold on
plot(u_x,rel_freq,"x")
plot(0:n,binopdf(0:n,n,p),"o")
hold off
legend("simulation","binopdf")
