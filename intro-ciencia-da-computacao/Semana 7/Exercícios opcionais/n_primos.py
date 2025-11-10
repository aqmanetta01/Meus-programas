def n_primos(n):
  cont = 1
  import math
  i = 3
  while i <= n:  #números a serem testados como primos
    j = 2
    c = 0
    while j < math.ceil(math.sqrt(i)) + 1:  #números que testam
      if (i % j) == 0:  #i é divisível por j => i não é primo
        c = 1  #aqui i nunca entrará em maiorp
        j = n  #aqui encerro o loop interno
      else:
        j = j + 1  #aqui o loop interno continua
    if c == 0:  #se i nao foi divisivel por nenhum j, ele é primo
      cont = cont + 1
    i = i + 1
  return cont
