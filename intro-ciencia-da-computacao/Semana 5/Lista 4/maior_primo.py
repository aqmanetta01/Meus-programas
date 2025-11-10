#este algoritmo tem a função de achar o maior número primo entre 2 e n


def maior_primo(n):
  import math
  i = 3
  maiorp = 2  #para qualquer n >=2, 2 sempre será o primeiro primo
  while i <= n:  #números a serem testados como primos
    j = 2
    c = 0
    while j < math.ceil(math.sqrt(i)) + 1:  #números que testam
      if (i % j) == 0:  #i é divisível por j => i não é primo
        c = 1  #aqui i nunca entrará em maiorp
        j = n  #aqui encerro o loop interno
      else:
        j = j + 1  #aqui o loop interno continua
    if c == 0:  #se i nao foi divisivel por nenhum j, ele é primo, e é candidato a ser o maior primo
      maiorp = i
    i = i + 1
  return (maiorp)
