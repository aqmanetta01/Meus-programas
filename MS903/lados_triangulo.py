import math

a = int(input())
b = int(input())
c = int(input())

if a >= b + c or b >= a + c or c >= a + b:
  print("Não podem ser os comprimentos dos lados de um triângulo")
else:
  s = (a + b + c) / 2
  A = math.sqrt(s * (s - a) * (s - b) * (s - c))
  p = 2 * s
  cos1 = (b**2 + c**2 - a**2) / (2 * b * c)
  cos2 = (b**2 + a**2 - c**2) / (2 * b * a)
  angulo1 = math.acos(cos1)
  angulo2 = math.acos(cos2)
  angulo3 = math.pi - angulo1 - angulo2
  print("São os comprimentos dos lados de um triângulo com área", A,
        "perímetro", p, "e ângulos internos", angulo1, ",", angulo2, "e",
        angulo3)
