function[] = Fg3(h)
n=1/h;

kw=zeros(1,n);
kg=zeros(1,n);
ko=zeros(n,n);
x=zeros(1,n);
y=zeros(1,n);
z=zeros(n,n);
for i=1:n
    x(i)=x(i)+i*h;
    y(i)=y(i)+i*h;
    kw(i)=x(i).^2;
    kg(i)=x(i).^2;
endfor
for i=1:n
    for j=1:n
        if (i+j)*h<=1
            lambda_w=kw(i)./0.5;
            lambda_g=kg(j)./0.3;
            ko(i,j)=(1-x(i)-y(j)).^2;
            lambda_o=ko(i,j)./1.0;
            lambda=lambda_w+lambda_g+lambda_o;
            z(i,j)=(lambda_g./lambda)./y(j);
        endif
    endfor
endfor
x;
y;
z;
[xx, yy] = meshgrid (x, y);
plot3(x,y,z)
mesh (x, y, z)
endfunction