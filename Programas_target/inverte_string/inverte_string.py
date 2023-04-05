string = input("Digite uma string: ")
string_inv = ""

for i in range(len(string)-1, -1, -1):
    string_inv += string[i]

print("A string invertida é:", string_inv)
