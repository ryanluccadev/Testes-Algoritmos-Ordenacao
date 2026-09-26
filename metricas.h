#ifndef METRICAS_H
#define METRICAS_H

#include <time.h>

typedef struct {
    char nome[30];
    long long comparacoes;
    long long trocas;
    double tempo_ms;
} Metricas;

void iniciarMetricas(Metricas *metrica, const char *nome);
clock_t iniciarCronometro(void);
void finalizarCronometro(Metricas *metrica, clock_t inicio);

#endif
