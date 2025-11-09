.globl _start

_start:
    jal main
    li a0, 0
    li a7, 93 # exit
    ecall


main:
    # Código aqui
    addi sp, sp, -4     # Reserva espaço na pilha
    call read           # a1 guarda o endereço da sequência de caracteres
    
    
    # leitura do sinal
    lbu a6, 0(a1)       # a6 guarda o sinal do número

    # leitura dos caracteres
    lbu a2, 1(a1)       # a2 guarda o primeiro caractere da seq. de carac.
    lbu a3, 2(a1)       # a3 guarda o segundo caractere da seq. de carac.
    lbu a4, 3(a1)       # a4 guarda o terceiro caractere da seq. de carac.
    lbu a5, 4(a1)       # a5 guarda o quarto caractere da seq. de carac.

    #conversão de char pra int
    addi a2, a2, -48    # converte char em int
    addi a3, a3, -48    # converte char em int
    addi a4, a4, -48    # converte char em int
    addi a5, a5, -48    # converte char em int
    li t6, 1000
    mul a2, a2, t6      # multiplica o valor original por 1000
    li t6, 100
    mul a3, a3, t6      # multiplica o valor original por 100
    li t6, 10
    mul a4, a4, t6      # multiplica o valor original por 10
    add a2, a2, a3      # soma a2 e a3 em a2
    add a2, a2, a4      # soma a2 e a4 em a2
    add a2, a2, a5      # soma a2 e a5 em a2

    # considera o sinal
    li t1, 43           # Código ascii do carac '+'
    beq t1, a6, cont2   # se for sinal '+', nada a fazer
    li t1, -1
    mul a2, a2, t1      # considera o sinal negativo
    cont2:
    sw a2, 0(a1)        # guarda Xc no endereço apontado por a1

    # leitura do sinal
    lbu a6, 6(a1)       # a6 guarda o sinal do número

    # leitura dos caracteres
    lbu a2, 7(a1)       # a2 guarda o primeiro caractere da seq. de carac.
    lbu a3, 8(a1)       # a3 guarda o segundo caractere da seq. de carac.
    lbu a4, 9(a1)       # a4 guarda o terceiro caractere da seq. de carac.
    lbu a5, 10(a1)      # a5 guarda o quarto caractere da seq. de carac.
    #conversão de char pra int
    addi a2, a2, -48    # converte char em int
    addi a3, a3, -48    # converte char em int
    addi a4, a4, -48    # converte char em int
    addi a5, a5, -48    # converte char em int
    li t6, 1000
    mul a2, a2, t6      # multiplica o valor original por 1000
    li t6, 100
    mul a3, a3, t6      # multiplica o valor original por 100
    li t6, 10
    mul a4, a4, t6      # multiplica o valor original por 10
    add a2, a2, a3      # soma a2 e a3 em a2
    add a2, a2, a4      # soma a2 e a4 em a2
    add a2, a2, a5      # soma a2 e a5 em a2
    # considera o sinal
    li t1, 43           # Código ascii do carac '+'
    beq t1, a6, cont3   # se for sinal '+', nada a fazer
    li t1, -1
    mul a2, a2, t1      # considera o sinal negativo
    cont3:              
    sw a2, 4(a1)        # guarda Yb no endereço apontado por a1 + 4

    # leitura dos tempos
    # leitura de Tr
    lbu a2, 12(a1)      # a2 guarda o primeiro caractere da seq. de carac.
    lbu a3, 13(a1)      # a3 guarda o segundo caractere da seq. de carac.
    lbu a4, 14(a1)      # a4 guarda o terceiro caractere da seq. de carac.
    lbu a5, 15(a1)      # a5 guarda o quarto caractere da seq. de carac.
    #conversão de char pra int
    addi a2, a2, -48    # converte char em int
    addi a3, a3, -48    # converte char em int
    addi a4, a4, -48    # converte char em int
    addi a5, a5, -48    # converte char em int
    li t6, 1000
    mul a2, a2, t6      # multiplica o valor original por 1000
    li t6, 100
    mul a3, a3, t6      # multiplica o valor original por 100
    li t6, 10
    mul a4, a4, t6      # multiplica o valor original por 10
    add a2, a2, a3      # soma a2 e a3 em a2
    add a2, a2, a4      # soma a2 e a4 em a2
    add a2, a2, a5      # soma a2 e a5 em a2
    sw a2, 8(a1)        # guarda Tr no endereço apontado por a1 + 8        

    # leitura de Ta
    lbu a2, 17(a1)      # a2 guarda o primeiro caractere da seq. de carac.
    lbu a3, 18(a1)      # a3 guarda o segundo caractere da seq. de carac.
    lbu a4, 19(a1)      # a4 guarda o terceiro caractere da seq. de carac.
    lbu a5, 20(a1)      # a5 guarda o quarto caractere da seq. de carac.
    #conversão de char pra int
    addi a2, a2, -48    # converte char em int
    addi a3, a3, -48    # converte char em int
    addi a4, a4, -48    # converte char em int
    addi a5, a5, -48    # converte char em int
    li t6, 1000
    mul a2, a2, t6      # multiplica o valor original por 1000
    li t6, 100
    mul a3, a3, t6      # multiplica o valor original por 100
    li t6, 10
    mul a4, a4, t6      # multiplica o valor original por 10
    add a2, a2, a3      # soma a2 e a3 em a2
    add a2, a2, a4      # soma a2 e a4 em a2
    add a2, a2, a5      # soma a2 e a5 em a2
    sw a2, 12(a1)       # guarda Ta no endereço apontado por a1 + 12

    # leitura de Tb
    lbu a2, 22(a1)      # a2 guarda o primeiro caractere da seq. de carac.
    lbu a3, 23(a1)      # a3 guarda o segundo caractere da seq. de carac.
    lbu a4, 24(a1)      # a4 guarda o terceiro caractere da seq. de carac.
    lbu a5, 25(a1)      # a5 guarda o quarto caractere da seq. de carac.
    #conversão de char pra int
    addi a2, a2, -48    # converte char em int
    addi a3, a3, -48    # converte char em int
    addi a4, a4, -48    # converte char em int
    addi a5, a5, -48    # converte char em int
    li t6, 1000
    mul a2, a2, t6      # multiplica o valor original por 1000
    li t6, 100
    mul a3, a3, t6      # multiplica o valor original por 100
    li t6, 10
    mul a4, a4, t6      # multiplica o valor original por 10
    add a2, a2, a3      # soma a2 e a3 em a2
    add a2, a2, a4      # soma a2 e a4 em a2
    add a2, a2, a5      # soma a2 e a5 em a2
    sw a2, 16(a1)       # guarda Tb no endereço apontado por a1 + 16

    # leitura de Tc
    lbu a2, 27(a1)      # a2 guarda o primeiro caractere da seq. de carac.
    lbu a3, 28(a1)      # a3 guarda o segundo caractere da seq. de carac.
    lbu a4, 29(a1)      # a4 guarda o terceiro caractere da seq. de carac.
    lbu a5, 30(a1)      # a5 guarda o quarto caractere da seq. de carac.
    #conversão de char pra int
    addi a2, a2, -48    # converte char em int
    addi a3, a3, -48    # converte char em int
    addi a4, a4, -48    # converte char em int
    addi a5, a5, -48    # converte char em int
    li t6, 1000
    mul a2, a2, t6      # multiplica o valor original por 1000
    li t6, 100
    mul a3, a3, t6      # multiplica o valor original por 100
    li t6, 10
    mul a4, a4, t6      # multiplica o valor original por 10
    add a2, a2, a3      # soma a2 e a3 em a2
    add a2, a2, a4      # soma a2 e a4 em a2
    add a2, a2, a5      # soma a2 e a5 em a2
    sw a2, 20(a1)       # guarda Tc no endereço apontado por a1 + 20


    # cálculo das diferenças dos tempos
    lw a2, 8(a1)        # a2 guarda o valor de Tr
    lw a3, 12(a1)       # a3 guarda o valor de Ta
    sub a3, a2, a3      # a3 guarda Tr - Ta
    lw a4, 16(a1)       # a4 guarda o valor de Tb
    sub a4, a2, a4      # a4 guarda Tr - Tb
    lw a5, 20(a1)       # a5 guarda o valor de Tc
    sub a5, a2, a5      # a5 guarda Tr - Tc
    # cálculo das diferenças de espaço
    li t1, 3
    mul a3, a3, t1
    mul a4, a4, t1
    mul a5, a5, t1
    li t1, 10
    div a3, a3, t1      # a3 guarda a distância para A
    div a4, a4, t1      # a4 guarda a distância para B
    div a5, a5, t1      # a5 guarda a distância para C

    # cálculo de y e x com base nas distâncias

    # cálculo de y 

    mul a2, a3, a3      # a2 guarda Da^2
    mv a7, a2           # a7 guarda Da^2
    lw a6, 4(a1)        # a6 guarda Yb
    mul a3, a6, a6      # a3 guarda Yb^2
    add a2, a2, a3      # a2 guarda Da^2 + Yb^2
    mul a4, a4, a4      # a4 guarda Db^2
    sub a2, a2, a4      # a2 guarda Da^2 + Yb^2 - Db^2
    li t1, 2
    mul a6, a6, t1      # a6 guarda 2 * Yb
    div a2, a2, a6      # a2 guarda y = (Da^2 + Yb^2 - Db^2) / (2 * Yb)
    mul a6, a5, a5      # a6 guarda Dc^2

    # cálculo de x  (a2 = y, a6 = Dc^2 , a7 = Da^2 )
    mul a4, a2, a2      # a4 guarda y^2
    sub a7, a7, a4      # a7 guarda Da^2 - y^2
    mv a4, a2           # a4 guarda y
    mv a2, a7           # a2 guarda Da^2 - y^2
    mv a7, a4           # a7 guarda y

    call raiz_quadrada  # a5 guarda a estimativa para a raiz ( usa a2, a3, a4, a5)

    lw a3, 0(a1)        # a3 = Xc

    sub a3, a5, a3      # a3 = x - Xc
    mul a3, a3, a3      # a3 = (x - Xc)^2
    mul a4, a7, a7      # a4 = y^2
    add a3, a3, a4      # a3 = (x - Xc)^2 - y^2
    sub a3, a3, a6      # a3 = (x - Xc)^2 - y^2 - Dc^2
    lw a4, 0(a1)        # a4 = Xc
    li t1, -1
    mul a5, a5, t1      # a5 = -sqrt()
    sub a4, a5, a4      # a4 = x - Xc
    mul a4, a4, a4      # a4 = (x - Xc)^2
    mul a2, a7, a7      # a2 = y^2
    add a4, a4, a2      # a4 = (x - Xc)^2 - y^2
    sub a4, a4, a6      # a4 = (x - Xc)^2 - y^2 - Dc^2
    # -x=>a5 , y = a7 , diffComX1=>a3 , diffComX2=>a4
    li t2, 0
    bge a4, t2, cont6
    li t1, -1
    mul a4, a4, t1
    cont6:

    bge a3, t2, cont7
    li t1, -1
    mul a3, a3, t1
    cont7:



    # comparar os valores de X1 e X2
    li a6, 45           # guarda o sinal negativo de x
    blt a4, a3, cont4   # se a diferença com X2 for menor, pula 
    addi a6, a6, -2     # guarda o sinal positivo de x
    cont4:
    li t1, -1
    mul a5, a5, t1
    # x=>a5 , y => a7
    sb a6, 0(a1)        # guarda o sinal de X

    #conversão de int pra char
    li t1, 1000         # Divisor para obter dígitos
    div a2, a5, t1      # obtém primeiro dígito e armazena em a2
    addi a2, a2, 48     # Converte o dígito para o caractere
    sb a2, 1(a1)        # armazena o primeiro caractere no endereço de a1 + 1 byte 

    rem a5, a5, t1      # armazena o resto em a5
    li t1, 100          # Divisor para obter dígitos
    div a3, a5, t1      # obtém segundo dígito e armazena em a3
    addi a3, a3, 48     # Converte o dígito para o caractere
    sb a3, 2(a1)        # armazena o segundo caractere no endereço de a1 + 2 bytes

    rem a5, a5, t1      # armazena o resto em a5
    li t1, 10           # Divisor para obter dígitos
    div a4, a5, t1      # obtém terceiro dígito e armazena em a4
    addi a4, a4, 48     # Converte o dígito para o caractere
    sb a4, 3(a1)        # armazena o terceiro caractere no endereço de a1 + 3 bytes

    rem a5, a5, t1      # armazena o resto em a5
    addi a5, a5, 48     # Converte o dígito para o caractere
    sb a5, 4(a1)        # armazena o quarto caractere no endereço de a1 + 4 bytes 

    # guardar o espaço 
    li a6, 32
    sb a6, 5(a1)
    mv a5, a7
    #  y = a5   

    li a6, 45           # guarda o sinal negativo de y

    li t1, 0
    blt a5, t1, cont5
    addi a6, a6, -2     # guarda o sinal positivo de x
    cont5:
    sb a6, 6(a1)        # guarda o sinal de y

    li t2, 0
    bge a5, t2, cont8
    li t1, -1
    mul a5, a5, t1
    cont8:

    #conversão de int pra char
    li t1, 1000         # Divisor para obter dígitos
    div a2, a5, t1      # obtém primeiro dígito e armazena em a2
    addi a2, a2, 48     # Converte o dígito para o caractere
    sb a2, 7(a1)        # armazena o primeiro caractere no endereço de a1 + 7 bytes 

    rem a5, a5, t1      # armazena o resto em a5
    li t1, 100          # Divisor para obter dígitos
    div a3, a5, t1      # obtém segundo dígito e armazena em a3
    addi a3, a3, 48     # Converte o dígito para o caractere
    sb a3, 8(a1)        # armazena o segundo caractere no endereço de a1 + 8 bytes

    rem a5, a5, t1      # armazena o resto em a5
    li t1, 10           # Divisor para obter dígitos
    div a4, a5, t1      # obtém terceiro dígito e armazena em a4
    addi a4, a4, 48     # Converte o dígito para o caractere
    sb a4, 9(a1)        # armazena o terceiro caractere no endereço de a1 + 9 bytes

    rem a5, a5, t1      # armazena o resto em a5
    addi a5, a5, 48     # Converte o dígito para o caractere
    sb a5, 10(a1)        # armazena o quarto caractere no endereço de a1 + 10 bytes
    li a5, 10
    sb a5, 11(a1)
    call write
    addi sp, sp, 4 
    ret
    
    


raiz_quadrada:          # a2 guarda o número a tirar a raiz
    li a5, 2            # primeira estimativa para a raiz
    mv a4, a5           # copia o valor 2 para a5, que será utilizado para tirar a média
    li t5, 21           # t5 guarda o número de laços 
    li t4, 0            # t4 guarda o índice do laço
    loop2:
        bge t4, t5, cont
        div a3, a2, a5  # divide n por a5 e guarda o resultado em a3
        add a5, a5, a3  # soma os dois valores
        div a5, a5, a4  # divide por 2 para obter a média em a5
        add t4, t4, 1   # atualiza o índice
        j loop2
    cont:
        ret             # a5 guarda a estimativa para a raiz


read:
    li a0, 0            # file descriptor = 0 (stdin)
    la a1, input_address # buffer
    li a2, 32           # size - Reads 32 bytes.
    li a7, 63           # syscall read (63)
    ecall
    ret

write:
    li a0, 1            # file descriptor = 1 (stdout)
    la a1, input_address       # buffer
    li a2, 12           # size - Writes 12 bytes.
    li a7, 64           # syscall write (64)
    ecall
    ret


.bss

input_address: .skip 0x31  # buffer

result: .skip 0x11