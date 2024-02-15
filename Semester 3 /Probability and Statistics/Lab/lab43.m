clear all;
clc;
clf

%geometric model

p=input("Please enter the probability of success: ")
while p<=0 || p>=1
    p=input("Please enter the probability of success: ")
end

s=input("Enter how many simulations do you want to create: ")
while s<1
    s=input("Enter how many simulations do you want to create: ")
end

x=zeros(1,s);
for ind=1:s
    while true
         u=rand();
         if u<p
            break
         else
            x(i)=x(i)+1;
         end
    end
end
u_x=unique(x)
n_x=hist(x,length(u_x))  
[u_x;n_x]  %fail nr fail succ nr succ

rel_freq=n_x/s
[u_x;rel_freq]

hold on
plot(u_x,rel_freq,"o")
plot(0:max(u_x),geopdf(0:max(u_x),p),"")
hold off
legend("simulation","geopdf")
