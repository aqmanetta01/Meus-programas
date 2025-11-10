def computador_escolhe_jogada(n,m):
  div = n//m
  resto = n%m
  
    
def usuario_escolhe_jogada(n,m):
  jogada =int(input("Quantas peças você vai tirar?"))
  while jogada>m:
    print("Oops! Jogada inválida! Tente de novo.")
    jogada =int(input("Quantas peças você vai tirar?"))
  return jogada



def partida():
  print("Bem-vindo ao jogo do NIM! Escolha:")
  print()
  print("1 - para jogar uma partida isolada")
  print("2 - para jogar um campeonato")
  partidas = int(input())
  if (partidas==1):
    print("Você escolheu uma partida isolada!")
    



  
  if jogada==1:
    print("Você tirou uma peça.")
  else:
    print("Voce tirou",jogada,"peças.")
  if (n-jogada==1):
    print("Agora resta apenas uma peça no tabuleiro.")
  else:
    print("Agora restam apenas",n-jogada,"no tabuleiro.")
  