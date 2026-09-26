#include <stdio.h>

#include "interface.h"


/* ============================================================
   CABECALHO
   ============================================================ */

void mostrarCabecalho(void)
{
    printf("\n");
    printf("============================================================\n");
    printf("        LABORATORIO DE TESTES DE ALGORITMOS\n");
    printf("============================================================\n");
}


/* ============================================================
   MENU DE GERACAO
   ============================================================ */

void mostrarMenuGeracao(void)
{
    printf("\n");
    printf("+----------------------------------------------------------+\n");
    printf("| GERACAO DO CONJUNTO                                      |\n");
    printf("+----------------------------------------------------------+\n");
    printf("| [1] Manual                                               |\n");
    printf("| [2] Aleatorio                                            |\n");
    printf("| [3] Ordenado                                             |\n");
    printf("| [4] Invertido                                            |\n");
    printf("+----------------------------------------------------------+\n");
}


/* ============================================================
   MENU DE MODO
   ============================================================ */

void mostrarMenuModo(void)
{
    printf("\n");
    printf("+----------------------------------------------------------+\n");
    printf("| MODO DE EXECUCAO                                         |\n");
    printf("+----------------------------------------------------------+\n");
    printf("| [1] Execucao normal                                      |\n");
    printf("| [2] Passo a passo                                        |\n");
    printf("+----------------------------------------------------------+\n");
}


/* ============================================================
   MENU DE ALGORITMO
   ============================================================ */

void mostrarMenuAlgoritmo(void)
{
    printf("\n");
    printf("+----------------------------------------------------------+\n");
    printf("| ESCOLHA DO ALGORITMO                                     |\n");
    printf("+----------------------------------------------------------+\n");
    printf("| [1] Bubble Sort                                          |\n");
    printf("| [2] Insertion Sort                                       |\n");
    printf("| [3] Selection Sort                                       |\n");
    printf("| [4] Merge Sort                                           |\n");
    printf("| [5] Quick Sort                                           |\n");
    printf("+----------------------------------------------------------+\n");
}


/* ============================================================
   MOSTRAR VETOR ORIGINAL
   ============================================================ */

void mostrarVetorOriginal(
    int vetor[],
    int tamanho
)
{
    printf("\n");
    printf("+----------------------------------------------------------+\n");
    printf("| VETOR ORIGINAL                                           |\n");
    printf("+----------------------------------------------------------+\n");

    printf(
        "Quantidade de itens: %d\n",
        tamanho
    );

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
}


/* ============================================================
   MOSTRAR VETOR ORDENADO
   ============================================================ */

void mostrarVetorOrdenado(
    int vetor[],
    int tamanho
)
{
    printf("\n");
    printf("+----------------------------------------------------------+\n");
    printf("| VETOR ORDENADO                                           |\n");
    printf("+----------------------------------------------------------+\n");

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
}


/* ============================================================
   MOSTRAR RESULTADOS
   ============================================================ */

void mostrarResultados(
    int tamanhoVetor,
    Metricas bubble,
    Metricas insertion,
    Metricas selection,
    Metricas merge,
    Metricas quick
)
{
    printf("\n");

    printf(
        "+--------------------------------------------------------------------------------+\n"
    );

    printf(
        "|                         RELATORIO DE DESEMPENHO                               |\n"
    );

    printf(
        "+--------------------------------------------------------------------------------+\n"
    );

    printf(
        "| Quantidade de itens: %-58d|\n",
        tamanhoVetor
    );

    printf(
        "+----------------------+------------+------------+------------+------------+------------+\n"
    );

    printf(
        "|                      |   Bubble   |  Insertion |  Selection |    Merge   |    Quick   |\n"
    );

    printf(
        "+----------------------+------------+------------+------------+------------+------------+\n"
    );

    printf(
        "| Comparacoes          | %10lld | %10lld | %10lld | %10lld | %10lld |\n",
        bubble.comparacoes,
        insertion.comparacoes,
        selection.comparacoes,
        merge.comparacoes,
        quick.comparacoes
    );

    printf(
        "| Trocas/movimentacoes | %10lld | %10lld | %10lld | %10lld | %10lld |\n",
        bubble.trocas,
        insertion.trocas,
        selection.trocas,
        merge.trocas,
        quick.trocas
    );

    printf(
        "| Tempo (ms)           | %10.3f | %10.3f | %10.3f | %10.3f | %10.3f |\n",
        bubble.tempo_ms,
        insertion.tempo_ms,
        selection.tempo_ms,
        merge.tempo_ms,
        quick.tempo_ms
    );

    printf(
        "+----------------------+------------+------------+------------+------------+------------+\n"
    );

    printf("\nAlgoritmos analisados:\n");

    printf("1. %s\n", bubble.nome);
    printf("2. %s\n", insertion.nome);
    printf("3. %s\n", selection.nome);
    printf("4. %s\n", merge.nome);
    printf("5. %s\n", quick.nome);
}


/* ============================================================
   PERGUNTAR SE DESEJA CONTINUAR
   ============================================================ */

int perguntarContinuar(void)
{
    int opcao;

    printf("\n");
    printf("+----------------------------------------------------------+\n");
    printf("| PROXIMA ACAO                                             |\n");
    printf("+----------------------------------------------------------+\n");
    printf("| [1] Fazer novo teste                                     |\n");
    printf("| [2] Encerrar programa                                    |\n");
    printf("+----------------------------------------------------------+\n");

    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        return 1;
    }

    return 0;
}


/* ============================================================
   ENCERRAMENTO
   ============================================================ */

void mostrarEncerramento(void)
{
    printf("\n");
    printf("============================================================\n");
    printf("                  PROGRAMA ENCERRADO\n");
    printf("============================================================\n");
    printf("Obrigado por utilizar o laboratorio!\n");
}