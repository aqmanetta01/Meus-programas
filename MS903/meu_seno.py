def meuseno(x, e):
  E = 1
  n = 2
  m = 1
  seno = x
  pot = x
  while (E - e > 0):
    m = m + 1
    E = E / (n * (n + 1))
    if (m % 2 == 0):
      pot = pot * x * x
      seno = seno - (pot * E)
    else:
      pot = pot * x * x
      seno = seno + (pot * E)
    n = n + 2
    print("seno=", seno)
  return seno


print(meuseno(float(input()), float(input())))
