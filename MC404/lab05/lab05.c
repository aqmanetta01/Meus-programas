#define STDIN_FD  0
#define STDOUT_FD 1

int read(int __fd, const void *__buf, int __n){
    int ret_val;
  __asm__ __volatile__(
    "mv a0, %1           # file descriptor\n"
    "mv a1, %2           # buffer \n"
    "mv a2, %3           # size \n"
    "li a7, 63           # syscall write code (63) \n"
    "ecall               # invoke syscall \n"
    "mv %0, a0           # move return value to ret_val\n"
    : "=r"(ret_val)  // Output list
    : "r"(__fd), "r"(__buf), "r"(__n)    // Input list
    : "a0", "a1", "a2", "a7"
  );
  return ret_val;
}

void write(int __fd, const void *__buf, int __n)
{
  __asm__ __volatile__(
    "mv a0, %0           # file descriptor\n"
    "mv a1, %1           # buffer \n"
    "mv a2, %2           # size \n"
    "li a7, 64           # syscall write (64) \n"
    "ecall"
    :   // Output list
    :"r"(__fd), "r"(__buf), "r"(__n)    // Input list
    : "a0", "a1", "a2", "a7"
  );
}

void exit(int code)
{
  __asm__ __volatile__(
    "mv a0, %0           # return code\n"
    "li a7, 93           # syscall exit (64) \n"
    "ecall"
    :   // Output list
    :"r"(code)    // Input list
    : "a0", "a7"
  );
}

void _start()
{
  int ret_code = main();
  exit(ret_code);
}

void hex_code(int val){
    char hex[11];
    unsigned int uval = (unsigned int) val, aux;

    hex[0] = '0';
    hex[1] = 'x';
    hex[10] = '\n';

    for (int i = 9; i > 1; i--){
        aux = uval % 16;
        if (aux >= 10)
            hex[i] = aux - 10 + 'A';
        else
            hex[i] = aux + '0';
        uval = uval / 16;
    }
    write(1, hex, 11);
}

void pack(int input, int start_bit, int end_bit, int *val){
    int num_bits = end_bit - start_bit + 1;
    int mascara = (1 << num_bits) - 1;
    input = mascara & input;
    input = (input<<start_bit);
    mascara = mascara << start_bit;
    *val = *val & ~mascara;
    *val = *val | input;

}

int charToInt (char* str){
    int sinal = 1;
    int numeros[5];
    for (int i = 0; i<5; i++){
        int sinal = 1;
        int char1, char2, char3 , char4;
        if (str[i*6]=='-'){
            sinal = -1; 
        }
        char1 = str[i*6 +1] - '0';
        char2 = str[i*6 +2] - '0';
        char3 = str[i*6 +3] - '0';
        char4 = str[i*6 +4] - '0';
        numeros[i] = char1 * 1000 + char2 * 100 + char3 * 10 + char4;
        numeros[i] = numeros[i] * sinal;
    }
    int valor = 0b00000000000000000000000000000000;
    pack(numeros[0],0,4, &valor);
    pack(numeros[1],5,11, &valor);
    pack(numeros[2],12,20, &valor);
    pack(numeros[3],21,24, &valor);
    pack(numeros[4],25,31, &valor);

    return valor;
}



#define STDIN_FD  0
#define STDOUT_FD 1

int main()
{
  char str[30];

  /* Read up to 20 bytes from the standard input into the str buffer */
  int n = read(STDIN_FD, str, 30);

  n = charToInt(str);
  hex_code(n);

  return 0;
}