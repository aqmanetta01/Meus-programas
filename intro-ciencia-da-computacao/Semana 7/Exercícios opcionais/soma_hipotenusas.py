def eh_hipotenusa(n):
  for i in range(1,n,1):
    for j in range(1,n,1):
      if (i**2 + j**2==n**2):
        return True
  return False
  
def soma_hipotenusas(n):
  soma = 0
  for i in range(2,n+1,1):
    if(eh_hipotenusa(i)==True):
      soma = soma + i
    
  return soma