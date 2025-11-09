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
    li t3, 4            # t3 guarda o número de laços
    li t2, 0            # t2 guarda o índice do laço
    loop1:
        bge t2, t3, cont1
        #conversão de char pra int
        lbu a2, 0(a1)       # a2 guarda o primeiro caractere da seq. de carac.
        lbu a3, 1(a1)       # a3 guarda o segundo caractere da seq. de carac.
        lbu a4, 2(a1)       # a4 guarda o terceiro caractere da seq. de carac.
        lbu a5, 3(a1)       # a5 guarda o quarto caractere da seq. de carac.
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


        call raiz_quadrada  # a5 guarda a estimativa para a raiz

        #conversão de int pra char
        li t0, 1000         # Divisor para obter dígitos
        div a2, a5, t0      # obtém primeiro dígito e armazena em a2
        addi a2, a2, 48     # Converte o dígito para o caractere
        sb a2, 0(a1)        # armazena o primeiro caractere no endereço de a1

        rem a5, a5, t0      # armazena o resto em a5
        li t0, 100          # Divisor para obter dígitos
        div a3, a5, t0      # obtém segundo dígito e armazena em a3
        addi a3, a3, 48     # Converte o dígito para o caractere
        sb a3, 1(a1)        # armazena o segundo caractere no endereço de a1 + 1 byte

        rem a5, a5, t0      # armazena o resto em a5
        li t0, 10           # Divisor para obter dígitos
        div a4, a5, t0      # obtém terceiro dígito e armazena em a4
        addi a4, a4, 48     # Converte o dígito para o caractere
        sb a4, 2(a1)        # armazena o terceiro caractere no endereço de a1 + 2 bytes

        rem a5, a5, t0      # armazena o resto em a5
        addi a5, a5, 48     # Converte o dígito para o caractere
        sb a5, 3(a1)        # armazena o segundo caractere no endereço de a1 + 3 bytes



        addi a1, a1, 5      # atualiza o endereço do próximo caractere a ser lido 
        add t2, t2, 1       # atualiza o índice
        j loop1
    cont1:
        addi a1, a1, -20    # retorna o endereço guardado em a1 para o endereço original
        call write
        addi sp, sp, 4 
        ret
    
    

    




raiz_quadrada:          # a2 guarda o número a tirar a raiz
    li a5, 2            # primeira estimativa para a raiz
    mv a4, a5           # copia o valor 2 para a5, que será utilizado para tirar a média
    li t5, 10           # t5 guarda o número de laços 
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
    li a2, 20           # size - Reads 20 bytes.
    li a7, 63           # syscall read (63)
    ecall
    ret

write:
    li a0, 1            # file descriptor = 1 (stdout)
    la a1, input_address       # buffer
    li a2, 20           # size - Writes 20 bytes.
    li a7, 64           # syscall write (64)
    ecall
    ret


.bss

input_address: .skip 0x20  # buffer

result: .skip 0x20