#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include "metricas.h"

void configurarPassoAPasso(int ativo);
void bubbleSort(int vetor[], int tamanho, Metricas *metrica);
void insertionSort(int vetor[], int tamanho, Metricas *metrica);
void selectionSort(int vetor[], int tamanho, Metricas *metrica);
void mergeSort(int vetor[], int esquerda, int direita, Metricas *metrica, int tamanho);
void quickSort(int vetor[], int inicio, int fim, Metricas *metrica, int tamanho);

#endif
