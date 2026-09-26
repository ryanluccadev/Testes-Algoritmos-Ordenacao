#include <string.h>
#include <time.h>

#include "metricas.h"


/* ============================================================
   INICIAR METRICAS
   ============================================================ */

void iniciarMetricas(
    Metricas *metrica,
    const char *nome
)
{
    strcpy(
        metrica->nome,
        nome
    );

    metrica->comparacoes = 0;

    metrica->trocas = 0;

    metrica->tempo_ms = 0.0;
}


/* ============================================================
   INICIAR CRONOMETRO
   ============================================================ */

clock_t iniciarCronometro(void)
{
    return clock();
}


/* ============================================================
   FINALIZAR CRONOMETRO
   ============================================================ */

void finalizarCronometro(
    Metricas *metrica,
    clock_t inicio
)
{
    clock_t fim = clock();

    metrica->tempo_ms =
        (
            (double)(fim - inicio)
            /
            CLOCKS_PER_SEC
        ) * 1000.0;
}