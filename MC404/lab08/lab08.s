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
    
    addi sp, sp, 4 
    ret
    

setPixel:
    li a0, 100 # x coordinate = 100
    li a1, 200 # y coordinate = 200
    li a2, 0xFFFFFFFF # white pixel
    li a7, 2200 # syscall setPixel (2200)
    ecall


open:
    la a0, input_file    # address for the file path
    li a1, 0             # flags (0: rdonly, 1: wronly, 2: rdwr)
    li a2, 0             # mode
    li a7, 1024          # syscall open 
    ecall

    




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

input_file: .asciz "image.pgm"

input_address: .skip 0x31  # buffer

result: .skip 0x11