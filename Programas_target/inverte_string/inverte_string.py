#Este programa tem por objetivo inverter a ordem de uma string de entrada inteira.
string = input("Digite uma string: ") #entrada da string.
string_inv = "" #string invertida inicializada como vazia.

for i in range(len(string)-1, -1, -1): #aqui fazemos um laço decrescente partindo da última letra da string.
    string_inv += string[i] #aqui adicionamos a letra à nova palavra que estava vazia.

print("A string invertida é:", string_inv) #mostra a nova palavra invertida.
