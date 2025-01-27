#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "funcoes.h"
#include "dados.h"

#define MAXv 300000

using namespace std;

int main() {
    srand(time(NULL)); // Inicializar o gerador de números aleatórios

    const int n = MAXv;

    Prato* pratos = (Prato*)malloc(n * sizeof(Prato));
    if (pratos == NULL) {
        cout << "Erro na alocação de memória." << endl;
        return 1;
    }

    criar_pratos(pratos, n, palavras, total_palavras);

    Prato* pratos_bubble = (Prato*)malloc(n * sizeof(Prato));
    Prato* pratos_quick = (Prato*)malloc(n * sizeof(Prato));
    if (pratos_bubble == NULL || pratos_quick == NULL) {
        cout << "Erro na alocação de memória para os pratos ordenados." << endl;
        free(pratos);
        return 1;
    }

    memcpy(pratos_bubble, pratos, n * sizeof(Prato));
    memcpy(pratos_quick, pratos, n * sizeof(Prato));

    clock_t inicio_bubble = clock();
    bubble_sort(pratos_bubble, n);
    clock_t fim_bubble = clock();

    cout << "Tempo de execução do Bubble Sort: " 
         << double(fim_bubble - inicio_bubble) / CLOCKS_PER_SEC << " segundos." << endl;

    embaralhar(pratos, n); 

    clock_t inicio_quick = clock();
    quick_sort(pratos_quick, 0, n - 1);
    clock_t fim_quick = clock();

    cout << "Tempo de execução do Quick Sort: " 
         << double(fim_quick - inicio_quick) / CLOCKS_PER_SEC << " segundos." << endl;

    free(pratos);
    free(pratos_bubble);
    free(pratos_quick);

    return 0;
}