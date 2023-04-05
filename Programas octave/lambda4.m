function[] = lambda4(h)
n=1/h;
vx=zeros(1,n);
vy=zeros(1,n);
vlambda=zeros(n,n);
sym x;
sym y;
syms kw(x,y);
syms ko(x,y);
syms kg(x,y);
kw(x,y)=x.^2;
kg(x,y)=y.^2;
ko(x,y)=(1-x-y).^2;
lambda_w(x,y)=kw(x,y)/0.5;
lambda_g(x,y)=kg(x,y)/0.3;
lambda_o(x,y)=ko(x,y)/1.0;
lambda(x,y)=lambda_w+lambda_g+lambda_o;
Fw(x,y)=lambda_w./lambda;
Fg(x,y)=lambda_g./lambda;
dFwdx=diff(Fw,x);
dFwdy=diff(Fw,y);
dFgdx=diff(Fg,x);
dFgdy=diff(Fg,y);
lambda1(x,y)=(dFwdx+dFgdy+sqrt(((dFwdx+dFgdy).^2)-(4*(dFwdx*dFgdy-dFgdx*dFwdy))))/2;
lambda2(x,y)=(dFwdx+dFgdy-sqrt(((dFwdx+dFgdy).^2)-(4*(dFwdx*dFgdy-dFgdx*dFwdy))))/2;
for i=1:n
    vx(i)=vx(i)+i*h;
    vy(i)=vy(i)+i*h;
endfor
for i=1:n
    for j=1:n
        if (i+j)*h<=1
            cx=h*i;
            cy=h*j;
            vlambda(i,j)=double(lambda2(cx,cy));
        endif
    endfor
endfor
[xx, yy] = meshgrid (vx, vy);
mesh (vx, vy,vlambda )
endfunction