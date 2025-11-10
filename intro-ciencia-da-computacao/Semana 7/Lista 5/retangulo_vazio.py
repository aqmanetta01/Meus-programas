largura = int(input("Digite a largura: "))
altura = int(input("Digite a altura: "))
print(largura * '#')
for i in range(altura - 2):
  print('#', end="")
  for j in range(largura - 2):
    print(' ', end="")
  print('#')
print(largura * '#')
