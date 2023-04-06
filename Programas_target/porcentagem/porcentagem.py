#Este programa tem por objetivo calcular a porcentagem de faturamento
#dos estados em destaque em relação ao total.
SP = 67836.43 #faturamento de cada estado e do total.
RJ = 36678.66
MG = 29229.88
ES = 27165.48
Outros = 19849.53
total = SP + RJ + MG + ES + Outros
#Escrita da porcentagem de cada estado com duas casas decimais.
print("A porcentagem do faturamento mensal pelo estado de SP foi:{:.2f}%".format(100*SP/total))
print("A porcentagem do faturamento mensal pelo estado de RJ foi:{:.2f}%".format(100*RJ/total))
print("A porcentagem do faturamento mensal pelo estado de MG foi:{:.2f}%".format(100*MG/total))
print("A porcentagem do faturamento mensal pelo estado de ES foi:{:.2f}%".format(100*ES/total))
print("A porcentagem do faturamento mensal pelos outros estados foi:{:.2f}%".format(100*Outros/total))