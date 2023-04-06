#Este programa tem por objetivo inidicar ao usuário se 
#um número de entrada pertence ou não à sequência de Fibonacci.
num=int(input())  #Entrada do número a ser testado.
a=0
b=1
c=0
d=0
if num == 0:  #caso especial:o número a ser testado é igual a 0.
    d=1
    print("O número",num,"pertence à sequência de Fibonacci!")
while num>=b:
    
    if b==num or a==num: #aqui sabemos quando o número pertence.
        d=1
        print("O número",num,"pertence à sequência de Fibonacci!")
        break
    else:
        c=a+b
        a=b
        b=c
    
if d == 0: #caso o programa não tenha achado este número na sequência de Fibonacci, ele não pertence.
    print("O número", num,"não pertence à sequência de Fibonacci")
    
