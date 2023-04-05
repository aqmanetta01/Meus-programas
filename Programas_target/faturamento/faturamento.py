#biblioteca que lê arquivos do tipo json.
import json

#passagem dos dados no formato json para uma lista em python.
with open(r"C:\Users\user\Desktop\github\Programas2\Programas_target\faturamento\dados.json") as mjson: 
    dados = json.load(mjson) 

#variáveis iniciais de min, max e média.
min_val=1000000
max_val=0
med_val=0

#Compara os valores iniciais de min e max com os valores na lista e calcula a média. 
#Aqui houve uma dúvida: os valores de faturamento zerados foram explicitamente desconsiderados da média,
#conforme solicitado. Porém, o mesmo não acontece para os valores mínimos, o que faria mais sentido
#(desconsiderar valores zerados da análise de valor de faturamento mínimo).
for i in range(len(dados)):
    if (dados[i]["valor"]<min_val):
        min_val=dados[i]["valor"]
    if (dados[i]["valor"]>max_val):
        max_val=dados[i]["valor"]
    if (dados[i]["valor"] != 0):
        med_val=med_val+dados[i]["valor"]/len(dados)

#imprime os valores de min, max e média.
print("O menor valor de faturamento durante o período foi, em reais:{:.2f}".format(min_val))
print("O maior valor de faturamento durante o período foi, em reais:{:.2f}".format(max_val))
print("O valor médio de faturamento durante o período foi, em reais:{:.2f}".format(med_val))
