#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "metricas.c"
#include "vetores.c"
#include "algoritmos.c"
#include "interface.c"


/* ============================================================
   EXECUTAR PASSO A PASSO
   ============================================================ */

void executarPassoAPasso(int vetorOriginal[], int tamanho)
{
    int opcao;
    int vetor[tamanho];
    Metricas metrica;

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = vetorOriginal[i];
    }

    mostrarMenuAlgoritmo();

    printf("Escolha o algoritmo: ");
    scanf("%d", &opcao);

    switch (opcao) {

        case 1:
            iniciarMetricas(&metrica, "Bubble Sort");
            break;

        case 2:
            iniciarMetricas(&metrica, "Insertion Sort");
            break;

        case 3:
            iniciarMetricas(&metrica, "Selection Sort");
            break;

        case 4:
            iniciarMetricas(&metrica, "Merge Sort");
            break;

        case 5:
            iniciarMetricas(&metrica, "Quick Sort");
            break;

        default:
            printf("\nOpcao invalida.\n");
            return;
    }

    printf("\n");
    printf("============================================================\n");
    printf("                    MODO PASSO A PASSO\n");
    printf("============================================================\n");

    printf("Algoritmo: %s\n", metrica.nome);
    printf("Quantidade de itens: %d\n", tamanho);

    configurarPassoAPasso(1);

    clock_t inicio = iniciarCronometro();

    switch (opcao) {

        case 1:
            bubbleSort(vetor, tamanho, &metrica);
            break;

        case 2:
            insertionSort(vetor, tamanho, &metrica);
            break;

        case 3:
            selectionSort(vetor, tamanho, &metrica);
            break;

        case 4:
            mergeSort(
                vetor,
                0,
                tamanho - 1,
                &metrica,
                tamanho
            );
            break;

        case 5:
            quickSort(
                vetor,
                0,
                tamanho - 1,
                &metrica,
                tamanho
            );
            break;
    }

    finalizarCronometro(&metrica, inicio);

    configurarPassoAPasso(0);

    printf("\n");
    printf("============================================================\n");
    printf("                    RESULTADO FINAL\n");
    printf("============================================================\n");

    mostrarVetorOrdenado(vetor, tamanho);

    printf("Algoritmo: %s\n", metrica.nome);
    printf("Quantidade de itens: %d\n", tamanho);
    printf("Comparacoes: %lld\n", metrica.comparacoes);
    printf("Trocas/movimentacoes: %lld\n", metrica.trocas);
    printf("Tempo: %.3f ms\n", metrica.tempo_ms);
}


/* ============================================================
   MAIN
   ============================================================ */

int main(void)
{
    int tamanhoVetor;
    int opcaoGeracao;
    int opcaoModo;
    int continuar = 1;

    mostrarCabecalho();

    while (continuar) {

        printf("\n");
        printf("============================================================\n");
        printf("                    TAMANHO DO VETOR\n");
        printf("============================================================\n");

        printf("Digite o tamanho do vetor: ");
        scanf("%d", &tamanhoVetor);

        if (tamanhoVetor <= 0) {
            printf("\nTamanho invalido.\n");
            continue;
        }

        int vetorOriginal[tamanhoVetor];

        mostrarMenuGeracao();

        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoGeracao);

        switch (opcaoGeracao) {

            case 1:
                preencherVetorManual(
                    vetorOriginal,
                    tamanhoVetor
                );
                break;

            case 2:
                preencherVetorAleatorio(
                    vetorOriginal,
                    tamanhoVetor
                );
                break;

            case 3:
                preencherVetorOrdenado(
                    vetorOriginal,
                    tamanhoVetor
                );
                break;

            case 4:
                preencherVetorInvertido(
                    vetorOriginal,
                    tamanhoVetor
                );
                break;

            default:
                printf("\nOpcao invalida.\n");
                continue;
        }

        mostrarVetorOriginal(
            vetorOriginal,
            tamanhoVetor
        );

        mostrarMenuModo();

        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoModo);

        if (opcaoModo == 2) {

            executarPassoAPasso(
                vetorOriginal,
                tamanhoVetor
            );

        } else if (opcaoModo == 1) {

            int vetorBubble[tamanhoVetor];
            int vetorInsertion[tamanhoVetor];
            int vetorSelection[tamanhoVetor];
            int vetorMerge[tamanhoVetor];
            int vetorQuick[tamanhoVetor];

            for (int i = 0; i < tamanhoVetor; i++) {

                vetorBubble[i] =
                    vetorOriginal[i];

                vetorInsertion[i] =
                    vetorOriginal[i];

                vetorSelection[i] =
                    vetorOriginal[i];

                vetorMerge[i] =
                    vetorOriginal[i];

                vetorQuick[i] =
                    vetorOriginal[i];
            }

            Metricas bubble;
            Metricas insertion;
            Metricas selection;
            Metricas merge;
            Metricas quick;

            iniciarMetricas(
                &bubble,
                "Bubble Sort"
            );

            iniciarMetricas(
                &insertion,
                "Insertion Sort"
            );

            iniciarMetricas(
                &selection,
                "Selection Sort"
            );

            iniciarMetricas(
                &merge,
                "Merge Sort"
            );

            iniciarMetricas(
                &quick,
                "Quick Sort"
            );

            configurarPassoAPasso(0);

            clock_t inicio;

            inicio = iniciarCronometro();

            bubbleSort(
                vetorBubble,
                tamanhoVetor,
                &bubble
            );

            finalizarCronometro(
                &bubble,
                inicio
            );

            inicio = iniciarCronometro();

            insertionSort(
                vetorInsertion,
                tamanhoVetor,
                &insertion
            );

            finalizarCronometro(
                &insertion,
                inicio
            );

            inicio = iniciarCronometro();

            selectionSort(
                vetorSelection,
                tamanhoVetor,
                &selection
            );

            finalizarCronometro(
                &selection,
                inicio
            );

            inicio = iniciarCronometro();

            mergeSort(
                vetorMerge,
                0,
                tamanhoVetor - 1,
                &merge,
                tamanhoVetor
            );

            finalizarCronometro(
                &merge,
                inicio
            );

            inicio = iniciarCronometro();

            quickSort(
                vetorQuick,
                0,
                tamanhoVetor - 1,
                &quick,
                tamanhoVetor
            );

            finalizarCronometro(
                &quick,
                inicio
            );

            mostrarResultados(
                tamanhoVetor,
                bubble,
                insertion,
                selection,
                merge,
                quick
            );

            printf("\nVetor final ordenado:\n");

            imprimirVetor(
                vetorBubble,
                tamanhoVetor
            );

        } else {

            printf("\nOpcao de modo invalida.\n");
        }

        continuar = perguntarContinuar();
    }

    mostrarEncerramento();

    return 0;
}