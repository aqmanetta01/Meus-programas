typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct voo {
    int numero_voo;
    Data data_voo;
    char cod_ori_voo[4];
    char cod_des_voo[4];
    double valor;
    int conf;
    int data_ok;
    int par_voo[100];
} Voo;

Data ler_data();
Voo ler_voo();

int compara_data(Data data1, Data data2);

int diferenca_data(Data data1, Data data2);

void cancelar(Voo voos[], int qtd_voos, int numero_voo);

void alterar(Voo voos[], int qtd_voos, int numero_voo, double novo_valor);

void planejar(Voo voos[], int qtd_voos, Data data_inicio, Data data_fim, char codigo_origem[]);
