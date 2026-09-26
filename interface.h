#ifndef INTERFACE_H
#define INTERFACE_H

#include "metricas.h"

void mostrarCabecalho(void);
void mostrarMenuGeracao(void);
void mostrarMenuModo(void);
void mostrarMenuAlgoritmo(void);
void mostrarVetorOriginal(int vetor[], int tamanho);
void mostrarVetorOrdenado(int vetor[], int tamanho);
void mostrarResultados(
    int tamanhoVetor,
    Metricas bubble,
    Metricas insertion,
    Metricas selection,
    Metricas merge,
    Metricas quick
);
int perguntarContinuar(void);
void mostrarEncerramento(void);

#endif
