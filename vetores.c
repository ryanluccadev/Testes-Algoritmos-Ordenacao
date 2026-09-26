#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "vetores.h"


/* ============================================================
   IMPRIMIR VETOR
   ============================================================ */

void imprimirVetor(
    int vetor[],
    int tamanho
)
{
    for (int i = 0; i < tamanho; i++) {

        printf(
            "%d",
            vetor[i]
        );

        if (i < tamanho - 1) {
            printf("  ");
        }
    }

    printf("\n");
}


/* ============================================================
   PREENCHIMENTO MANUAL
   ============================================================ */

void preencherVetorManual(
    int vetor[],
    int tamanho
)
{
    printf("\n");
    printf("============================================================\n");
    printf("                    PREENCHIMENTO MANUAL\n");
    printf("============================================================\n");

    for (int i = 0; i < tamanho; i++) {

        printf(
            "Digite o numero %d: ",
            i + 1
        );

        scanf(
            "%d",
            &vetor[i]
        );
    }
}


/* ============================================================
   PREENCHIMENTO ALEATORIO
   ============================================================ */

void preencherVetorAleatorio(
    int vetor[],
    int tamanho
)
{
    int minimo;
    int maximo;

    printf("\n");
    printf("============================================================\n");
    printf("                    GERACAO ALEATORIA\n");
    printf("============================================================\n");

    printf("Digite o valor minimo: ");
    scanf("%d", &minimo);

    printf("Digite o valor maximo: ");
    scanf("%d", &maximo);

    if (minimo > maximo) {

        int temp = minimo;

        minimo = maximo;
        maximo = temp;
    }

    srand(
        (unsigned int)time(NULL)
    );

    for (int i = 0; i < tamanho; i++) {

        vetor[i] =
            minimo +
            rand() %
            (maximo - minimo + 1);
    }

    printf(
        "\nVetor aleatorio gerado com sucesso!\n"
    );
}


/* ============================================================
   PREENCHIMENTO ORDENADO
   ============================================================ */

void preencherVetorOrdenado(
    int vetor[],
    int tamanho
)
{
    int inicio;

    printf("\n");
    printf("============================================================\n");
    printf("                    VETOR ORDENADO\n");
    printf("============================================================\n");

    printf("Digite o valor inicial: ");
    scanf("%d", &inicio);

    for (int i = 0; i < tamanho; i++) {

        vetor[i] =
            inicio + i;
    }

    printf(
        "\nVetor ordenado gerado com sucesso!\n"
    );
}


/* ============================================================
   PREENCHIMENTO INVERTIDO
   ============================================================ */

void preencherVetorInvertido(
    int vetor[],
    int tamanho
)
{
    int inicio;

    printf("\n");
    printf("============================================================\n");
    printf("                    VETOR INVERTIDO\n");
    printf("============================================================\n");

    printf("Digite o valor inicial: ");
    scanf("%d", &inicio);

    for (int i = 0; i < tamanho; i++) {

        vetor[i] =
            inicio - i;
    }

    printf(
        "\nVetor invertido gerado com sucesso!\n"
    );
}