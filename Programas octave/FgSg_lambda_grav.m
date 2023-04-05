function[] = FgSg_lambda_grav(h)
n=1/h;
vx=zeros(1,n);
vy=zeros(1,n);
vlambda=zeros(n,n);
FgSg=zeros(n,n);
sym x;
sym y;
syms kw(x,y);
syms ko(x,y);
syms kg(x,y);
kw(x,y)=x.^2;
kg(x,y)=y.^2;
ko(x,y)=(1-x-y).^2;
ro_w=1;
ro_o=0.7;
ro_g=5.76*10^-2;
g=9.8;
lambda_w(x,y)=kw(x,y)/0.5;
lambda_g(x,y)=kg(x,y)/0.3;
lambda_o(x,y)=ko(x,y)/1;
lambda(x,y)=lambda_w+lambda_g+lambda_o;
Fw(x,y)=lambda_w./lambda;

Fg(x,y)=lambda_g./lambda;
Gw(x,y)=lambda_w*((1-Fw(x,y))*(ro_w-ro_o)-Fg(x,y)*(ro_g-ro_o))*g;
Gg(x,y)=lambda_g*((1-Fg(x,y))*(ro_g-ro_o)-Fw(x,y)*(ro_w-ro_o))*g;
Hw(x,y)=Fw(x,y)+Gw(x,y);
Hg(x,y)=Fg(x,y)+Gg(x,y);
dHwdx=diff(Hw,x);
dHwdy=diff(Hw,y);
dHgdx=diff(Hg,x);
dHgdy=diff(Hg,y);
lambda1(x,y)=(dHwdx+dHgdy+sqrt(((dHwdx+dHgdy).^2)-(4*(dHwdx*dHgdy-dHgdx*dHwdy))))/2;
lambda2(x,y)=(dHwdx+dHgdy-sqrt(((dHwdx+dHgdy).^2)-(4*(dHwdx*dHgdy-dHgdx*dHwdy))))/2;
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
            FgSg(i,j)=double(Fg(cx,cy)/cy);
        endif
    endfor
endfor
[xx, yy] = meshgrid (vx, vy);
mesh (vx, vy,FgSg-vlambda )
endfunction