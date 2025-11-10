typedef struct {
    // você é livre pra definir o bloco aqui
    int x;
    int z;
    int y;
    int M;
} Bloco;

// é obrigatório implementar os protótipos seguintes

/**
 * Cria uma matriz de altitudes representando
 * o relevo de um mundo.
 **/
int **calcularAltitudes(int m, int n, int seed);

/**
 * Cria um novo mundo representado por uma matriz
 * de blocos alocada dinamicamente.
 **/
Bloco ***criarMundo(int m, int n, int **altitudes, int seed);

/**
 * Explora o mapa de um mundo e devolve o tempo
 * necessário para minerar todo ele. Além disso,
 * devolve a quantidade de alguns minérios de
 * interesse.
 **/
double explorarMundo(
    Bloco ***blocos, int m, int n, int **altitudes, double t,
    int *qtdDiamante, int *qtdOuro, int *qtdFerro, int *qtdBlocos);

// você pode adicionar e implementar outros protótipos
// que forem necessários

void le_entrada(int *m, int *n, int *seed,double *t);

void imprime( double t,int *qtdDiamante, int *qtdOuro, int *qtdFerro, int *qtdBlocos);
