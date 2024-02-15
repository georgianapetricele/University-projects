x=linspace(0,3);
y1=(x.^5)/10;
y2=x.*sin(x);
y3=cos(x);
plot(x,y1,'g',x,y2,'b--',x,y3,'c.');
title("Plot")
legend("power","sin","cos")


