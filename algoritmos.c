#include <stdio.h>

#include "algoritmos.h"


/* ============================================================
   CONTROLE DO PASSO A PASSO
   ============================================================ */

static int modoPassoAPasso = 0;


/* ============================================================
   CONFIGURAR PASSO A PASSO
   ============================================================ */

void configurarPassoAPasso(
    int ativo
)
{
    modoPassoAPasso = ativo;
}


/* ============================================================
   MOSTRAR PASSO
   ============================================================ */

static void mostrarPasso(
    int vetor[],
    int tamanho,
    const char *mensagem
)
{
    if (!modoPassoAPasso) {
        return;
    }

    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("%s\n", mensagem);

    printf("Vetor: ");

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
    printf("------------------------------------------------------------\n");

    printf("Pressione ENTER para continuar...");

    int c;

    while (
        (c = getchar()) != '\n' &&
        c != EOF
    ) {
    }

    getchar();
}


/* ============================================================
   BUBBLE SORT
   ============================================================ */

void bubbleSort(
    int vetor[],
    int tamanho,
    Metricas *metrica
)
{
    for (int i = 0; i < tamanho - 1; i++) {

        for (
            int j = 0;
            j < tamanho - 1 - i;
            j++
        ) {

            metrica->comparacoes++;

            if (vetor[j] > vetor[j + 1]) {

                int temp = vetor[j];

                vetor[j] = vetor[j + 1];

                vetor[j + 1] = temp;

                metrica->trocas++;

                mostrarPasso(
                    vetor,
                    tamanho,
                    "Bubble Sort - troca realizada"
                );
            }
        }
    }
}


/* ============================================================
   INSERTION SORT
   ============================================================ */

void insertionSort(
    int vetor[],
    int tamanho,
    Metricas *metrica
)
{
    for (int i = 1; i < tamanho; i++) {

        int chave = vetor[i];

        int j = i - 1;

        while (j >= 0) {

            metrica->comparacoes++;

            if (vetor[j] <= chave) {
                break;
            }

            vetor[j + 1] = vetor[j];

            metrica->trocas++;

            mostrarPasso(
                vetor,
                tamanho,
                "Insertion Sort - movimentacao realizada"
            );

            j--;
        }

        vetor[j + 1] = chave;

        metrica->trocas++;

        mostrarPasso(
            vetor,
            tamanho,
            "Insertion Sort - elemento inserido"
        );
    }
}


/* ============================================================
   SELECTION SORT
   ============================================================ */

void selectionSort(
    int vetor[],
    int tamanho,
    Metricas *metrica
)
{
    for (
        int i = 0;
        i < tamanho - 1;
        i++
    ) {

        int menor = i;

        for (
            int j = i + 1;
            j < tamanho;
            j++
        ) {

            metrica->comparacoes++;

            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        if (menor != i) {

            int temp = vetor[i];

            vetor[i] = vetor[menor];

            vetor[menor] = temp;

            metrica->trocas++;

            mostrarPasso(
                vetor,
                tamanho,
                "Selection Sort - troca realizada"
            );
        }
    }
}


/* ============================================================
   INTERCALACAO DO MERGE SORT
   ============================================================ */

static void intercalar(
    int vetor[],
    int esquerda,
    int meio,
    int direita,
    Metricas *metrica,
    int tamanho
)
{
    int tamanhoEsquerda =
        meio - esquerda + 1;

    int tamanhoDireita =
        direita - meio;

    int esquerdaVetor[tamanhoEsquerda];
    int direitaVetor[tamanhoDireita];

    for (
        int i = 0;
        i < tamanhoEsquerda;
        i++
    ) {
        esquerdaVetor[i] =
            vetor[esquerda + i];
    }

    for (
        int j = 0;
        j < tamanhoDireita;
        j++
    ) {
        direitaVetor[j] =
            vetor[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = esquerda;

    while (
        i < tamanhoEsquerda &&
        j < tamanhoDireita
    ) {

        metrica->comparacoes++;

        if (
            esquerdaVetor[i] <=
            direitaVetor[j]
        ) {

            vetor[k] =
                esquerdaVetor[i];

            i++;

        } else {

            vetor[k] =
                direitaVetor[j];

            j++;
        }

        metrica->trocas++;

        mostrarPasso(
            vetor,
            tamanho,
            "Merge Sort - movimentacao realizada"
        );

        k++;
    }

    while (i < tamanhoEsquerda) {

        vetor[k] =
            esquerdaVetor[i];

        metrica->trocas++;

        mostrarPasso(
            vetor,
            tamanho,
            "Merge Sort - movimentacao realizada"
        );

        i++;
        k++;
    }

    while (j < tamanhoDireita) {

        vetor[k] =
            direitaVetor[j];

        metrica->trocas++;

        mostrarPasso(
            vetor,
            tamanho,
            "Merge Sort - movimentacao realizada"
        );

        j++;
        k++;
    }
}


/* ============================================================
   MERGE SORT
   ============================================================ */

void mergeSort(
    int vetor[],
    int esquerda,
    int direita,
    Metricas *metrica,
    int tamanho
)
{
    if (esquerda < direita) {

        int meio =
            esquerda +
            (direita - esquerda) / 2;

        mergeSort(
            vetor,
            esquerda,
            meio,
            metrica,
            tamanho
        );

        mergeSort(
            vetor,
            meio + 1,
            direita,
            metrica,
            tamanho
        );

        intercalar(
            vetor,
            esquerda,
            meio,
            direita,
            metrica,
            tamanho
        );
    }
}


/* ============================================================
   PARTICIONAMENTO DO QUICK SORT
   ============================================================ */

static int particionar(
    int vetor[],
    int inicio,
    int fim,
    Metricas *metrica,
    int tamanho
)
{
    int pivo =
        vetor[inicio];

    int esquerda =
        inicio + 1;

    int direita =
        fim;

    while (esquerda <= direita) {

        while (esquerda <= fim) {

            metrica->comparacoes++;

            if (
                vetor[esquerda] >= pivo
            ) {
                break;
            }

            esquerda++;
        }

        while (direita > inicio) {

            metrica->comparacoes++;

            if (
                vetor[direita] < pivo
            ) {
                break;
            }

            direita--;
        }

        if (esquerda < direita) {

            int temp =
                vetor[esquerda];

            vetor[esquerda] =
                vetor[direita];

            vetor[direita] =
                temp;

            metrica->trocas++;

            mostrarPasso(
                vetor,
                tamanho,
                "Quick Sort - troca realizada"
            );

            esquerda++;
            direita--;
        }
    }

    int temp =
        vetor[inicio];

    vetor[inicio] =
        vetor[direita];

    vetor[direita] =
        temp;

    metrica->trocas++;

    mostrarPasso(
        vetor,
        tamanho,
        "Quick Sort - pivo colocado na posicao correta"
    );

    return direita;
}


/* ============================================================
   QUICK SORT
   ============================================================ */

void quickSort(
    int vetor[],
    int inicio,
    int fim,
    Metricas *metrica,
    int tamanho
)
{
    if (inicio < fim) {

        int posicaoPivo =
            particionar(
                vetor,
                inicio,
                fim,
                metrica,
                tamanho
            );

        quickSort(
            vetor,
            inicio,
            posicaoPivo - 1,
            metrica,
            tamanho
        );

        quickSort(
            vetor,
            posicaoPivo + 1,
            fim,
            metrica,
            tamanho
        );
    }
}