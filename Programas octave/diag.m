function[] = diag(h)
n=1/h;
vx=zeros(1,n);
vy=zeros(1,n);
vz=zeros(n,n);
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
zw=Fw/x;
zg=Fg/y;
dFwdx=diff(Fw,x);
dFwdy=diff(Fw,y);
dFgdx=diff(Fg,x);
dFgdy=diff(Fg,y);
J=[dFwdx,dFwdy;dFgdx,dFgdy];
lambda1(x,y)=(dFwdx+dFgdy+sqrt(((dFwdx+dFgdy).^2)-(4*(dFwdx*dFgdy-dFgdx*dFwdy))))/2;
lambda2(x,y)=(dFwdx+dFgdy-sqrt(((dFwdx+dFgdy).^2)-(4*(dFwdx*dFgdy-dFgdx*dFwdy))))/2;
J1=[dFwdx-lambda1(x,y),dFwdy;dFgdx,dFgdy-lambda1(x,y)];
M1=[1;-J1(2,1)/J1(2,2)];
J2=[dFwdx-lambda2(x,y),dFwdy;dFgdx,dFgdy-lambda2(x,y)];
M2=[1;-J2(2,1)/J2(2,2)];
M=[M1, M2];
iM=[M(2,2),-1;-M(2,1),1]/(M(2,2)-M(2,1));
D=iM*J*M;
zJ1=[dFwdx-zw,dFwdy;dFgdx,dFgdy-zw];
Mz1=[1;-zJ1(2,1)/zJ1(2,2)];
zJ2=[dFwdx-zg,dFwdy;dFgdx,dFgdy-zg];
Mz2=[1;-zJ2(2,1)/zJ2(2,2)];
Mz=[Mz1, Mz2];
iMz=[Mz(2,2),-1;-Mz(2,1),1]/(Mz(2,2)-Mz(2,1));
Dz=iMz*J*M;

for i=1:n
    vx(i)=vx(i)+i*h;
    vy(i)=vy(i)+i*h;
endfor

d11(x,y)=D(1,1);
d22(x,y)=D(2,2);
dz11(x,y)=Dz(1,1);
dz22(x,y)=Dz(2,2);
      
for i=1:n
  for j=1:n
    if (i+j)*h<=1
      cx=h*i;
      cy=h*j;
      vz(i,j)=double(d11(cx,cy))-double(dz11(cx,cy));
    endif
  endfor
endfor
vz
[xx, yy] = meshgrid (vx, vy);
mesh (vx, vy,vz )
endfunction