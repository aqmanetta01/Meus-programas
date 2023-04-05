num=int(input())
a=0
b=1
c=0
d=0
if num == 0:
    d=1
    print("O número",num,"pertence à sequência de Fibonacci!")
while num>=b:
    
    if b==num or a==num:
        d=1
        print("O número",num,"pertence à sequência de Fibonacci!")
        break
    else:
        c=a+b
        a=b
        b=c
    
if d == 0:
    print("O número", num,"não pertence à sequência de Fibonacci")
    
