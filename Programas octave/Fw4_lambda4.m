function[] = Fw4_lambda4(h)
n=1/h;

kw=zeros(1,n);
kg=zeros(1,n);
ko=zeros(n,n);
xv=zeros(1,n);
yv=zeros(1,n);
zv=zeros(n,n);

vlambda=zeros(n,n);
sym x;
sym y;
syms kw(x,y);
syms ko(x,y);
syms kg(x,y);
kw(x,y)=x.^2;
kg(x,y)=y.^2.;
ko(x,y)=(1-x-y).^2;
lambda_w(x,y)=kw(x,y)/0.5;
lambda_g(x,y)=kg(x,y)/0.3;
lambda_o(x,y)=ko(x,y)/1;
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
    xv(i)=xv(i)+i*h;
    yv(i)=yv(i)+i*h;
    kw(i)=xv(i).^2;
    kg(i)=xv(i).^2;
endfor
for i=1:n
    for j=1:n
        if (i+j)*h<=1
            lambda_w=kw(i)./0.5;
            lambda_g=kg(j)./0.3;
            ko(i,j)=(1-xv(i)-yv(j)).^2;
            lambda_o=ko(i,j)./1.0;
            lambda=lambda_w+lambda_g+lambda_o;
            aux=(lambda_w./lambda)./xv(i);
            zv(i,j)=double(aux);
        endif
    endfor
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

[xx, yy] = meshgrid (xv, yv);
mesh (xv, yv,zv-vlambda )
endfunction