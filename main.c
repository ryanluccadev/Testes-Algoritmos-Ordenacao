// ============================================================
// Projeto: Laboratório de Testes de Algoritmos de Ordenação
// Autor: Ryan Lucca Marques Pereira
// Objetivo: Testar e comparar o desempenho de algoritmos de ordenação
// ============================================================

#include <stdio.h>

// Função do Bubble Sort (ordenação por bolha)
void bubbleSort(int vetor[], int tamanho) {
    int i, j, temp; // Variáveis usadas na ordenação

    // Percorre o vetor várias vezes
    for (i = 0; i < tamanho - 1; i++) {

        // Compara os valores vizinhos
        for (j = 0; j < tamanho - 1 - i; j++) {

            // Verifica se o valor atual é maior que o próximo
            if (vetor[j] > vetor[j + 1]) {

                // Troca os dois valores de posição
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// Função do Insertion Sort (ordenação por inserção)
void insertionSort(int vetor[], int tamanho) {
    int i, j, chave; // Variáveis usadas na ordenação

    // Começa pela segunda posição do vetor
    for (i = 1; i < tamanho; i++) {

        // Guarda o valor que será colocado na posição correta
        chave = vetor[i];

        // Começa a verificar o valor anterior
        j = i - 1;

        // Enquanto houver valores maiores que a chave
        while (j >= 0 && vetor[j] > chave) {

            // Move o valor uma posição para frente
            vetor[j + 1] = vetor[j];

            // Volta uma posição
            j--;
        }

        // Coloca a chave na posição correta
        vetor[j + 1] = chave;
    }
}

// Função do Selection Sort (ordenação por seleção)
void selectionSort(int vetor[], int tamanho) {
    int i, j, menor, temp; // Variáveis usadas na ordenação

    // Percorre o vetor
    for (i = 0; i < tamanho - 1; i++) {

        // Considera a posição atual como a menor
        menor = i;

        // Procura um valor menor nas próximas posições
        for (j = i + 1; j < tamanho; j++) {

            // Verifica se encontrou um valor menor
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        // Troca o menor valor encontrado com o valor atual
        temp = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = temp;
    }
}

int main() {
    int tamanho; // Guarda o tamanho do vetor
    int opcao;   // Guarda a opção escolhida no menu

    // Exibe o título principal do programa
    printf("\n=== LABORATÓRIO DE TESTES DE ALGORITMOS DE ORDENAÇÃO ===\n\n");

    // Pede para o usuário informar o tamanho
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // Cria o vetor com o tamanho informado pelo usuário
    int vetor[tamanho];

    // Gera os números base do vetor
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i;
    }

    // Mostra o menu de seleção dos algoritmos
    printf("\nSelecao de algoritmos:\n\n");
    printf("1 - Bolha\n");
    printf("2 - Insercao\n");
    printf("3 - Selecao\n");
    printf("4 - Merge\n");
    printf("5 - Quick\n");

    // Pede para o usuário escolher um algoritmo
    printf("\nEscolha um algoritmo: ");
    scanf("%d", &opcao);

    // Verifica qual algoritmo foi escolhido
    if (opcao == 1) {

        // Chama a função Bubble Sort
        bubbleSort(vetor, tamanho);

        printf("\nBubble Sort executado.\n");
    }

    else if (opcao == 2) {

        // Chama a função Insertion Sort
        insertionSort(vetor, tamanho);

        printf("\nInsertion Sort executado.\n");
    }

    else if (opcao == 3) {

        // Chama a função Selection Sort
        selectionSort(vetor, tamanho);

        printf("\nSelection Sort executado.\n");
    }

    else {

        // Caso escolha Merge ou Quick
        // Esses algoritmos ainda não foram implementados
        printf("\nErro.\n");
    }

    // Mostra o vetor depois da ordenação
    printf("\nVetor ordenado: \n");

    // Percorre o vetor para mostrar seus valores
    for (int i = 0; i < tamanho; i++) {

        // Mostra o valor da posição atual
        printf("%d ", vetor[i]);
    }

    return 0; // Finaliza o programa
}