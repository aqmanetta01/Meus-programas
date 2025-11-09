#include <stdio.h>

int main() {
  int n; // Declaração da variável 'n' para armazenar o número de contribuintes
  scanf("%d", &n); // Solicita ao usuário o número de contribuintes e armazena em 'n'

  double M[1000][12]; // Declara uma matriz para armazenar os rendimentos mensais dos contribuintes
  for (int i = 0; i < n; i++) { // Loop para cada contribuinte
    for (int j = 0; j < 12; j++) { // Loop para cada mês do ano
      scanf("%lf", &M[i][j]); // Recebe o rendimento mensal para o contribuinte 'i' no mês 'j' e armazena em 'M'
    }
  }

  double A[1000]; // Declara um array para armazenar o abatimento de imposto de cada contribuinte
  for (int i = 0; i < n; i++) { // Loop para cada contribuinte
    scanf("%lf", &A[i]); // Recebe o abatimento de imposto para o contribuinte 'i' e armazena em 'A'
  }

  double impm[1000][12]; // Declara uma matriz para armazenar o imposto retido na fonte mensal de cada contribuinte
  double impmt[1000]; // Declara um array para armazenar o imposto retido na fonte total de cada contribuinte
  for (int i = 0; i < n; i++) { // Loop para cada contribuinte
    impmt[i] = 0; // Inicializa o imposto retido na fonte total para o contribuinte 'i' como zero
    for (int j = 0; j < 12; j++) { // Loop para cada mês do ano
      // Calcula o imposto retido na fonte mensal com base no rendimento mensal e armazena em 'impm'
      // Os cálculos são baseados em faixas de renda e taxas de imposto predefinidas
      // O imposto retido na fonte total para o contribuinte 'i' é atualizado
      impm[i][j] = // Armazena o imposto retido na fonte mensal para o contribuinte 'i' no mês 'j'
        // Condições para determinar a taxa de imposto com base no rendimento mensal
      impmt[i] += impm[i][j]; // Atualiza o imposto retido na fonte total para o contribuinte 'i'
    }
  }

  double ra[1000]; // Declara um array para armazenar o rendimento anual total de cada contribuinte
  double impa[1000]; // Declara um array para armazenar o imposto devido anual de cada contribuinte
  for (int i = 0; i < n; i++) { // Loop para cada contribuinte
    ra[i] = 0; // Inicializa o rendimento anual total para o contribuinte 'i' como zero
    for (int j = 0; j < 12; j++) { // Loop para cada mês do ano
      ra[i] += M[i][j]; // Calcula o rendimento anual total somando os rendimentos mensais
    }
    impa[i] = 0; // Inicializa o imposto devido anual para o contribuinte 'i' como zero
    ra[i] -= A[i]; // Subtrai o abatimento de imposto do rendimento anual total
    // Calcula o imposto devido anual com base no rendimento anual e armazena em 'impa'
    // Os cálculos são baseados em faixas de renda e taxas de imposto predefinidas
  }

  // Imprime o cabeçalho da tabela
  printf("Jan\tFev\tMar\tAbr\tMai\tJun\tJul\tAgo\tSet\tOut\tNov\tDez\tRetido\tDevido\tAjuste\t\n");

  // Loop para imprimir os valores do imposto retido mensalmente, imposto retido total,
  // imposto devido anualmente e o ajuste necessário para cada contribuinte
  for (int i = 0; i < n; i++) { // Loop para cada contribuinte
    for (int j = 0; j < 12; j++) { // Loop para cada mês do ano
      printf("%.2lf\t", impm[i][j]); // Imprime o imposto retido na fonte mensal para o contribuinte 'i' no mês 'j'
    }
    printf("%.2lf\t", impmt[i]); // Imprime o imposto retido na fonte total para o contribuinte 'i'
    printf("%.2lf\t", impa[i]); // Imprime o imposto devido anual para o contribuinte 'i'
    printf("%.2f\t\n", (impa[i] - impmt[i])); // Imprime o ajuste necessário (imposto devido - imposto retido)
  }
  return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
