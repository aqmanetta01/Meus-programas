def problema_parcelas(m, n):
  teto_mdc = int(n / m)

  mdc = maior_divisor(n, teto_mdc)
  lista = []
  for i in range(1, m):
    lista.append(mdc)
  resto = n - (m - 1) * mdc
  lista.append(resto)
  soma = 0
  for i in range(len(lista)):
    soma += lista[i]
  print("Soma = ", soma)
  print("Tamanho da lista = ", len(lista))
  print("Divisibilidade do último elemento = ", lista[-1] % mdc == 0)
  return lista


def maior_divisor(p, q):
  maior_div = None  # Inicializa o maior divisor como None
  for i in range(1, q + 1):  # Itera de 1 até q, inclusive
    if p % i == 0:  # Verifica se i é divisor de p
      maior_div = i  # Atualiza o maior divisor encontrado
  return maior_div  # Retorna o maior divisor encontrado


while (True):
  m = int(input("Insira o número de parcelas:"))
  n = int(input("Insira a soma das parcelas:"))
  print("A solução para o problema das parcelas é:", problema_parcelas(m, n))
