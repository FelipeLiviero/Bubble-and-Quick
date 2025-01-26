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

    // Alocar memória para os pratos
    Prato* pratos = (Prato*)malloc(n * sizeof(Prato));
    if (pratos == NULL) {
        cerr << "Erro na alocação de memória." << endl;
        return 1;
    }

    // Criar os pratos aleatórios
    criar_pratos(pratos, n, palavras, total_palavras);

    // Clonar os pratos para aplicar diferentes algoritmos de ordenação
    Prato* pratos_bubble = (Prato*)malloc(n * sizeof(Prato));
    Prato* pratos_quick = (Prato*)malloc(n * sizeof(Prato));
    if (pratos_bubble == NULL || pratos_quick == NULL) {
        cerr << "Erro na alocação de memória para os pratos ordenados." << endl;
        free(pratos);
        return 1;
    }

    memcpy(pratos_bubble, pratos, n * sizeof(Prato));
    memcpy(pratos_quick, pratos, n * sizeof(Prato));

    // Medir o tempo de execução do Bubble Sort
    clock_t inicio_bubble = clock();
    bubble_sort(pratos_bubble, n);
    clock_t fim_bubble = clock();

    // Medir o tempo de execução do Quick Sort
    clock_t inicio_quick = clock();
    quick_sort(pratos_quick, 0, n - 1);
    clock_t fim_quick = clock();

    // Mostrar os tempos de execução
    cout << "Tempo de execução do Bubble Sort: " 
         << double(fim_bubble - inicio_bubble) / CLOCKS_PER_SEC << " segundos." << endl;

    cout << "Tempo de execução do Quick Sort: " 
         << double(fim_quick - inicio_quick) / CLOCKS_PER_SEC << " segundos." << endl;

    // Liberar memória
    free(pratos);
    free(pratos_bubble);
    free(pratos_quick);

    return 0;
}