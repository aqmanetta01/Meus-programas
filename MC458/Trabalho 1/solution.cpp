#include "lib.hpp"
#include <iostream>
#include <vector>

using namespace std;

/* 
    Se quiser crie funcoes e variaveis aqui    
*/

// has_edge(int i, int j): retorna true se há tirolesa do monte i para o monte j,
//                         nesse sentido, e false caso contrario.

//minhas funções:
std::vector<int> solve_recursivo(const std::vector<int>& lista) {
    std::vector<int> l_sai;
    std::vector<int> l_entra;
    if (lista.size() <= 1) {
        return lista;
    } else {
        for (int i = 0; i < lista.size() - 1; i++) {
            if (has_edge(lista.back(), lista[i])) {
                l_sai.push_back(lista[i]);
            } else {
                l_entra.push_back(lista[i]);
            }
        }
        std::vector<int> L1 = solve_recursivo(l_sai);
        std::vector<int> L2 = solve_recursivo(l_entra);
        L2.push_back(lista.back());
        L2.insert(L2.end(), L1.begin(), L1.end());
        return L2;
    }
}

std::vector<int> solve(int N) {
    std::vector<int> l_sai;
    std::vector<int> l_entra;
    for (int i = 1; i < N; i++) {
        if (has_edge(N, i)) {
            l_sai.push_back(i);
        } else {
            l_entra.push_back(i);
        }
    }

    std::vector<int> L1 = solve_recursivo(l_sai);
    std::vector<int> L2 = solve_recursivo(l_entra);
    L2.push_back(N);
    L2.insert(L2.end(), L1.begin(), L1.end());
    return L2;
}

/* 
    Nao altere nada da main!!!! 
    Para testar seu codigo veja "lib.h"
*/
int main(int argc, char *argv[]) {

    char *filename = NULL;
    if(argc > 1)
        filename = argv[1];

    int n;
    initialize_has_edge(n, filename);

    vector<int> path = solve(n);
    int result = check_path(path, n);
    cout << result << '\n';
    return result;
}
