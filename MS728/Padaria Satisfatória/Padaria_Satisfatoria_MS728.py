import pulp
import more_itertools
import pandas as pd
import os

# Caminho absoluto da pasta atual do script
BASE_DIR = os.path.dirname(os.path.abspath(__file__))

# Caminhos dos arquivos
caminho_custo = os.path.join(BASE_DIR, "dados", "dadosCusto(2).xlsx")
caminho_tempo = os.path.join(BASE_DIR, "dados", "dadosTempo.xlsx")
caminho_demanda = os.path.join(BASE_DIR, "dados", "dadosDemanda.xlsx")

# Leitura dos dados
dataFrameDistancia = pd.read_excel(caminho_custo, index_col=0)
dataFrameTempo = pd.read_excel(caminho_tempo, index_col=0)
dataFrameDemanda = pd.read_excel(caminho_demanda, index_col=0)


#Nomes dos clientes
nomesDosLocais = list(dataFrameDistancia.columns.values)

print(nomesDosLocais)

#Transformar os dados em matriz do sumpy 
matrizDistancia = dataFrameDistancia.to_numpy()
print(matrizDistancia)

#Transformar os dados em matriz do numpy
matrizTempo = dataFrameTempo.to_numpy()
print(matrizTempo)

#Transformar os dados em matriz do numpy
matrizDemanda = dataFrameDemanda.to_numpy()
print(matrizDemanda)

#Quantidade de linhas da matriz (quantidade de clientes a ser visitado)
totalDeLocais = len(matrizDistancia)
#Criação do modelo matemático
prob = pulp.LpProblem("rota", pulp.LpMinimize)

#Quantidade de veículos k
veiculos = list(['v1', 'v2'])
totalDeVeiculos = len(veiculos)

#Criação da matriz de variáveis de decisão
x = [[[0 for k in range(totalDeVeiculos)] for j in range(totalDeLocais)] for i in range(totalDeLocais)]

print(x)
print(veiculos[0],veiculos[1])
print(totalDeVeiculos)

#Transformando em variável
for i in range(totalDeLocais):
  for j in range(totalDeLocais):
    if i!=j and i!=totalDeLocais+1 and j!=0:
      for k in range(totalDeVeiculos):
        x[i][j][k] = pulp.LpVariable(nomesDosLocais[i] + nomesDosLocais[j] + veiculos[k], cat='Binary')

#Função Objetivo
soma = 0
for k in range(totalDeVeiculos):
  for i in range(totalDeLocais):
    for j in range(totalDeLocais):
      if i!=j:
        soma += matrizDistancia[i][j]*x[i][j][k]
prob += soma
print(prob)
#Restrições de saída (todos os veículos saem do depósito)
saida = [0 for k in range(totalDeVeiculos)]

for k in range(totalDeVeiculos):
  saida[k] = 0
  for j in range(1,totalDeLocais):
    saida[k] += x[0][j][k]
  prob += saida[k] == 1

#Restrições de chegada (todos os veículos voltam ao depósito)
chegada = [0 for k in range(totalDeVeiculos)]
voltaDeposito = totalDeLocais-1

for k in range(totalDeVeiculos):
  chegada[k] = 0
  for i in range(totalDeLocais-1):
    chegada[k] += x[i][voltaDeposito][k]
  prob+=chegada[k]==1
print(prob)
#Manutenção de fluxo
conservacaoEntrada = [[0 for k in range(totalDeVeiculos)] for h in range(totalDeLocais)]
conservacaoSaida = [[0 for k in range(totalDeVeiculos)] for h in range(totalDeLocais)]

for k in range(totalDeVeiculos):
  for h in range(1,totalDeLocais-1):
    for i in range(totalDeLocais-1):
      conservacaoEntrada[h][k]+=x[i][h][k]
    for j in range(1,totalDeLocais):
      conservacaoSaida[h][k] += x[h][j][k]
    prob+=conservacaoEntrada[h][k] == conservacaoSaida[h][k]


print(prob)

#Cada cliente é atendido apenas uma única vez
atendimentoClientes = [0 for i in range(totalDeLocais)]

for i in range(1,totalDeLocais-1):
  for j in range(totalDeLocais):
    for k in range(totalDeVeiculos):
      atendimentoClientes[i] += x[i][j][k]
  prob+=atendimentoClientes[i]==1
print(prob)

#Eliminação de sub-rotas
conjuntoDeLocais = range(1,totalDeLocais-1)
print(conjuntoDeLocais)

for k in range(totalDeVeiculos):
  for subConjunto in list(more_itertools.powerset(conjuntoDeLocais)):
    if len(subConjunto) >= 2 and len(subConjunto) <= totalDeLocais - 1:
      restricao = 0
      for i in subConjunto:
        for j in subConjunto:
          restricao += x[i][j][k]
      prob+= restricao <= len(subConjunto) -1
print(prob)

#Tempo disponível para realização da rota
T = 4800*60

tempo = 0

for k in range(totalDeVeiculos):
  for i in range(totalDeLocais-1):
    for j in range(1,totalDeLocais):
      if i!=j:
        tempo += matrizTempo[i][j]*x[i][j][k]
  prob += tempo <= T

Q = 45

for k in range(totalDeVeiculos):
  quant = 0
  for i in range(1,totalDeLocais-1):
    for j in range(1,totalDeLocais):
      if i!=j:
        quant += matrizDemanda[i-1][0]*x[i][j][k]
  prob += quant <= Q
print(prob)

#tempoInicio = time.clock()
status = prob.solve()
#tempoFinal = time.clock()
#tempoTotal = tempoFinal - tempoInicio
pulp.LpStatus[status]

#print("Tempo total do algoritmo: " + str(tempoTotal))

custoResposta = pulp.value(prob.objective)

solucao = []
for variavel in prob.variables():
  if variavel.varValue != 0:
    solucao.append([variavel.name, variavel.varValue])
#solucao.append(["Tempo total do algoritmo: "+str(tempoTotal)])
solucao.append(["Custo total: "+str(custoResposta)])
#solucao.append(["Status: "+str(statusProb)])

dataFrameSolucao = pd.DataFrame(solucao)

dataFrameSolucao.to_excel('Resposta para rota.xlsx', index=False, header=False)


dataFrameSolucao
