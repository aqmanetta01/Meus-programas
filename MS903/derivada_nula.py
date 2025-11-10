
import sympy as sp
import numpy as np

x = sp.symbols('x')
y =  x**2
a = -3
b = 3
n = 10000

vetor_x = np.linspace(a,b,n)
vetor_y = np.zeros(n)

for i in range(len(vetor_x)):
    vetor_y[i] = y.subs(x,vetor_x[i])
#print(vetor_y)
#print(vetor_x)
    
for i in range(len(vetor_x)):
    try:
        if ((vetor_y[i]-vetor_y[i+1]>0 and vetor_y[i+1]-vetor_y[i+2]<0) or (vetor_y[i]-vetor_y[i+1]<0 and vetor_y[i+1]-vetor_y[i+2]>0)):
            print("Ponto de derivada nula: x = ", vetor_x[i+1])
        elif( vetor_y[i]-vetor_y[i+1]==0):
            print("Ponto de derivada nula: x = ", (vetor_x[i]+vetor_x[i+1])/2)
            print(vetor_x[i])
            print(vetor_x[i+1])

            
    except: IndexError
        
    
