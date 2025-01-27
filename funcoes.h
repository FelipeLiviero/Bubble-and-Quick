#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <time.h>

using namespace std;

typedef struct {
    char nome_prato[50];
    int prioridade;
    int tempo_preparo;
} Prato;

void bubble_sort(Prato* pratos, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pratos[j].prioridade < pratos[j + 1].prioridade || 
                (pratos[j].prioridade == pratos[j + 1].prioridade && pratos[j].tempo_preparo > pratos[j + 1].tempo_preparo)) {
                Prato temp = pratos[j];
                pratos[j] = pratos[j + 1];
                pratos[j + 1] = temp;
            }
        }
    }
}

int particao(Prato* pratos, int low, int high) {
    Prato pivo = pratos[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (pratos[j].prioridade > pivo.prioridade || 
            (pratos[j].prioridade == pivo.prioridade && pratos[j].tempo_preparo < pivo.tempo_preparo)) {
            i++;
            Prato temp = pratos[i];
            pratos[i] = pratos[j];
            pratos[j] = temp;
        }
    }
    Prato temp = pratos[i + 1];
    pratos[i + 1] = pratos[high];
    pratos[high] = temp;
    return (i + 1);
}

void quick_sort(Prato* pratos, int low, int high) {
    if (low < high) {
        int pi = particao(pratos, low, high);
        quick_sort(pratos, low, pi - 1);
        quick_sort(pratos, pi + 1, high);
    }
}

void criar_pratos(Prato* pratos, int n, const char palavras[][20], int total_palavras) {
    for (int i = 0; i < n; i++) {
        int idx1 = rand() % total_palavras;
        int idx2 = rand() % total_palavras;
        int idx3 = rand() % total_palavras;

        string nome = string(palavras[idx1]) + " " + string(palavras[idx2]) + " " + string(palavras[idx3]);

                                        // c_str foi usado pois a funcao precisava de um const char
        strncpy(pratos[i].nome_prato, nome.c_str(), sizeof(pratos[i].nome_prato) - 1); // STRNCPY evita problemas de estouro de buffer
        pratos[i].nome_prato[sizeof(pratos[i].nome_prato) - 1] = '\0';

        pratos[i].prioridade = rand() % 10 + 1;        // Prioridade de 1 a 10
        pratos[i].tempo_preparo = rand() % 60 + 1;     // Tempo de preparo de 1 a 60 minutos
    }
}

void embaralhar(Prato* pratos, int total_pratos) {
    for (int i = total_pratos - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Prato temp = pratos[i];
        pratos[i] = pratos[j];
        pratos[j] = temp;
    }
}

#endif