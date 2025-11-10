function[] = coacus(v1,rho1,v2,rho2)
n=360; #aqui "n" ser? o tamanho dos vetores.
vtheta=linspace(0,pi/2,n); #"vtheta" ser? o vetor linear do ?ngulo.
R=zeros(1,n); #"R" ser? o vetor do coeficiente de reflex?o.

for i=1:n 
  theta_t=asin(v2*sin(vtheta(i))/v1); #aqui, para cada ?ngulo de incid?ncia, teremos um valor para o ?ngulo de transmiss?o, conforme a Lei de Snell.
  R(i)=(v2*rho2*cos(vtheta(i))-v1*rho1*cos(theta_t))/(v2*rho2*cos(vtheta(i))+v1*rho1*cos(theta_t)); #aqui, usamos a f?rmula para o coeficiente de reflex?o em função das velocidades, das densidades e dos ?ngulos.
endfor

plot(vtheta,R);
ylabel('R(\theta_i)')
xlabel('\theta_i' )
endfunction