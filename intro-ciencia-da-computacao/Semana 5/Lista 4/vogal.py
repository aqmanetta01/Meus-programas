def vogal(letra):
  lista_vogais = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
  for i in lista_vogais:
    if i == letra:
      return True
  return False