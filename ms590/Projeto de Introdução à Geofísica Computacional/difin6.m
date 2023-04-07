function[] = difin6(u0,ut0,c,t1,t2,x1,x2)
# Instru??es para utiliza??o do c?igo:
# O usu?io dever? fornecer 7 par?metros: u0, uma fun??o dependente de x, que ser? entendida como a fun??o u no tempo t=0; ut0, uma fun??o dependente de x, que ser? entendida como a derivada da fun??o u em rela??o ao tempo no tempo t=0; c, a velocidade da onda, que aqui foi entendida como uma fun??o de x, mas que pode ser declarada como uma constante; t1, o tempo inicial; t2, o tempo final; x1, o valor de x m?ximo; e x2, o valor de x m?nimo. O resultado do gr?fico ? um plot 3D da fun??o u nos intervalos de tempo e espa?o. Caso o usu?rio queira o resultado em um ?nico tempo espec?fico, poder? usar t1=t2. O resultado ser? uma curva no espa?o tridimensional.
dt=10^(-1); #aqui se delimita o valor do passo que a fun??o utilizar?. para intervalos de tempo e espa?o muito grandes, recomenda-se aumentar o passo.
dx=dt; #aqui trabalhamos com a hip?tese de que o passo em t deve ser igual ao passo em x.
nx=(x2-x1)*10;
nt=(t2)*10;
nt2=(t2-t1)*10;
vt=zeros(1,nt+1); #nas linhas 9 a 12, criamos os vetores que utilizaremos como eixos x e t, e tamb?m para a fun??o da velocidade de onda.
vt2=zeros(1,nt2+1); # a exist?ncia de um segundo vetor para t explicaremos mais adiante.
vx=zeros(1,nx+1);
vc=zeros(1,nx+1);

for i=1:nt+1 #aqui criamos o vetor original dos tempos, que vai de 0 ? t2.
    vt(i)=(i-1)*dt;
endfor

for i=1:nt2+1 #aqui criamos o vetor final dos tempos, que vai de t1 ? t2.
    vt2(i)=(i-1)*dt+t1;
endfor

for i=1:nx+1 #aqui criamos os vetores x, que vai de x1 ? x2, e e c, que vai de c(x1) ? c(x2).
    vx(i)=(i-1)*dx+x1;
    x=i*dx+x1;
    vc(i)=c(x);
endfor

u=zeros(nx+1,nt+1); #aqui criamos a matriz da fun??o u, que ? calculada de 0 ? t2 e de x1 ? x2.
u2=zeros(nx+1,nt2+1); #aqui criamos a matriz da fun??o u2, que ? calculada de t1 ? t2 e de x1 ? x2.

for i=1:nx+1 #aqui inicializamos a primeira coluna de u, como sendo o valor de u0(x)
    x=(i-1)*dx+x1;
    u(i,1)=u0(x);
endfor

for i=1:nx+1 #aqui inicializamos a segunda coluna de u, utilizando o valor da fun??o na coluna anterior e a fun??o ut0(x), que ? a derivada de u em t=0.
    x=(i-1)*dx+x1;
    u(i,2)=ut0(x)*dt+u(i,1);
endfor

for j=3:nt+1 #aqui inicializamos a primeira e a ?ltima linha de u, utilizando como condi??es de contorno a hip?tese de que a derivada de u em rela??o ao tempo em t0 permanece constante para todos os pontos no mesmo x, isto ?, supondo que as fronteiras n?o mudam.
  x=dx+x1;
  xn2=(nx)*dx+x1;
  u(1,j)=ut0(x)*dx+u(1,j-1);
  u(nx+1,j)=ut0(xn2)*dx+u(nx+1,j-1);
endfor

for j=2:nt #aqui calculamos o valor de u no restante da matriz utilizando o m?todo das diferen?as finitas.
  for i=2:nx 
    u(i,j+1)=2*u(i,j)-u(i,j-1)+(vc(i))**2*dt**2*(u(i+1,j)-2*u(i,j)+u(i-1,j))/dt**2; 
  endfor
endfor

for j=1:nt2+1 #aqui utilizamos a matriz u para calcular a matriz u2, considerando as condi??es que estabelecemos anteriormente.
  for i=1:nx 
    u2(i,j)=u(i,j+nt-nt2);
  endfor
endfor

[xx, yy] = meshgrid (vt2, vx); #aqui utilizamos a fun??o meshgrid para criar a malha que usaremos na fun??o u2.
mesh (vt2, vx, u2) #aqui usamos a fun??o mesh que utiliza a malha que criamos e plota a fun??o u2 como uma superf?cie em rela??o a malha tempoXespa?o.

endfunction
