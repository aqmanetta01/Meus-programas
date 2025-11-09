
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

#define STDIN_FD  0
#define STDOUT_FD 1

int hexaToDecimal (char* str, int n){

  int sinal = 1;
  if (str[2] == '8' || str[2] == '9' || str[2] == 'a' || str[2] == 'b' || str[2] == 'c' || str[2] == 'd' || str[2] == 'e' || str[2] == 'f'){
    sinal = -1; //define o sinal do hexadecimal
  }

  int decimal = 0;
  int expoente = 0;
  int digito;
  for (int i = n -2 ; i>1 ; i--){
    int potenciaDeDezesseis = 1;
    if (str[i] >= 'a' && str[i] <= 'f') {
      digito = str[i] - 'a' + 10;
    } else {
      digito = str[i] - 0x30; 
    }
    int j = 0;
    while (j<expoente){  //calcula a potencia de 16 com base na posição do caractere
      potenciaDeDezesseis = potenciaDeDezesseis * 16;
      j++;
    }
    decimal = decimal +  digito * potenciaDeDezesseis;
    expoente++;
  }
  decimal = decimal * sinal;
  return decimal;
  

}

int charToInt (char* str, int n){
  int retorno = 0;

  if (str[0] == '-'){
    //while(str[i] != '-'){
      
    //}
  }
  char retornoChar[2];
  retornoChar[0] = retorno + '0';
  retornoChar[1] = '\n';
  //write(STDOUT_FD, (void *) retornoChar, 2);

  return 1;
}

void intToChar (int decimalInt, char *str){

  int tamanho = 0;
  int quociente = decimalInt;
  while (quociente != 0) {
    tamanho++;
    quociente = quociente / 10;
  }
  int sinal = 1;
  if (decimalInt < 0){
    str[0]='-';
    sinal = -1;
    decimalInt= -decimalInt;
    for (int i = tamanho ; i >= 1; i--) {
      str[i] = (decimalInt % 10) + '0';
      decimalInt = decimalInt / 10;
      //write(STDOUT_FD, str, n);

    }
    tamanho++;
    //str[tamanho+1] = '\n';
  } else{
    for (int i = tamanho - 1; i >= 0; i--) {
        str[i] = (decimalInt % 10) + '0';
        decimalInt = decimalInt / 10;
    }
    //str[tamanho] = '\n';
  }
  str[tamanho] = '\n';


  


}

int decimalToBinario (int decimal, char *binarioChar){
  //binarioChar[0] = '0';
  //binarioChar[1] = 'b';
  int sinal = 1; 
  int tamanho = 0;
  if(decimal < 0){
    sinal = -1;
    decimal = -decimal;
  } 
  int i = 0;
  while (decimal != 0){
  binarioChar[i] = (decimal % 2) + '0';
  decimal = decimal / 2;
  i++;
  tamanho ++ ;
  }
  char binarioChar2[tamanho];
  for(int i = 0;i<tamanho;i++){
  binarioChar2[i] = binarioChar[tamanho -1 -i];
  }
  if (sinal == -1){
    for(int i = 1;i<tamanho;i++){
      if(binarioChar2[i] == '0'){
        binarioChar2[i]= '1';
      } else{
        binarioChar2[i]= '0';
      }
    }
  }
  
  for (int i=0; i<tamanho; i++){
    binarioChar[i] = binarioChar2[i];
  }
  binarioChar[tamanho]='\n';
  return tamanho;
}




int main()
{
  char str[20];

  /* Read up to 20 bytes from the standard input into the str buffer */
  int n = read(STDIN_FD, str, 20);

  char quebraDeLinha[1];
  quebraDeLinha[0] = '\n';

  int decimal;
  if (str[0] == '0' && str[1] == 'x'){ //hexadecimal
    decimal = hexaToDecimal(str,n); //transforma hexadecimal em decimal
    //intToChar (decimal, str); //transforma decimal em caracteres

    //write(STDOUT_FD, str, n); //imprime decimal

    /* Trata e imprime binário */
    char inicioBin[2];
    inicioBin[0]='0';
    inicioBin[1]='b';
    char binarioChar [32];
    int tamanhoDoBinario;
    tamanhoDoBinario = decimalToBinario(decimal, binarioChar); //transforma decimal em binario e retorna tamanhoBinario
    write(STDOUT_FD, (void *) inicioBin, 2); //imprime binário
    write(STDOUT_FD, (void *) binarioChar, tamanhoDoBinario);
    write(STDOUT_FD, (void *) quebraDeLinha, 1);


    /* Trata e imprime decimal */
    int tamanhoDoDecimal = 0;
    while (str[tamanhoDoDecimal] != '\n') {
      tamanhoDoDecimal++;
    }
    intToChar (decimal, str); //transforma decimal em caracteres
    write(STDOUT_FD, str, tamanhoDoDecimal); //imprime decimal
  } else{
    decimal = charToInt(str,n);
    

  }

  //write(STDOUT_FD, str, n);


  //char nChar[2];
  //nChar[0] = n + '0';
  //nChar[1] = '\n';
  //char decimalChar[2];
  //decimalChar[0] = decimal + '0';
  //decimalChar[1] = '\n';
  //write(STDOUT_FD, (void *) nChar, 2);
  //write(STDOUT_FD, (void *) decimalChar, 2);

  /* Write n bytes from the str buffer to the standard output */
  //write(STDOUT_FD, str, n);


  return 0;
}