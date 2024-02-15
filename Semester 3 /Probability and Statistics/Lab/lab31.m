clear all;
clc;

txt = input("Enter the model you want to select:norm,t,f,chi2","s");
alfa=input("Enter the the order alfa for the quantile: ");
beta=input("Enter the the order beta for the quantile: ");
switch txt
    case "norm"
        fprintf("Normal distribution");
        n=input("Enter the first param(miu) for normal d. model: \n");
        m=input("Enter the second param(sigma) for normal d. model: \n");
        a1=normcdf(0,n,m);
        b11=normcdf(1,n,m);
        b12=normcdf(-1,n,m);
        %xa=p(X<xa)=alfa
        xa=norminv(alfa,n,m);
        xb=norminv(1-beta,n,m);
    case "t"
        fprintf("Student distribution\n")
        n=input("Enter the first param for student d. model: ");
        a1=tcdf(0,n);
        b11=tcdf(1,n);
        b12=tcdf(-1,n);
         xa=tinv(alfa,n);
         xb=tinv(1-beta,n);
    case "f"
        fprintf("Fisher distribution\n")
        n=input("Enter the first param for fisher d. model: \n");
        m=input("Enter the second param for fisher d. model: \n");
        a1=fcdf(0,n,m);
        b11=fcdf(1,n,m);
        b12=fcdf(-1,n,m);
        xa=finv(alfa,n,m);
        xb=finv(1-beta,n,m);
    case "chi2"
        fprintf("Chi2 distribution\n")
        n=input("Enter the first param for chi2 d. model: ");
        a1=chi2cdf(0,n);
        b11=chi2(1,n);
        b12=chi2(-1,n);
        xa=chi2inv(alfa,n);
        xb=chi2inv(1-beta,n);
     otherwise 
        fprintf("Not a valid input"); 
end
    a2=1-a1;
    b1=b11-b12;
    b2=1-b1;  %b2=1-p(x>-1 and x<1) the negation
    fprintf("a1.p(x<=0)=%9.5f\n",a1);
    fprintf("a2.p(x>0)=%9.5f\n",a2);
    fprintf("b1.p(-1<=x<=1)=%9.5f\n",b1);
    fprintf("b2.p(-1<=x<=1)=%9.5f\n",b2);
    fprintf("xa.p(-1<=x<=1)=%9.5f\n",xa);
    fprintf("xb.p(-1<=x<=1)=%9.5f\n",xb);