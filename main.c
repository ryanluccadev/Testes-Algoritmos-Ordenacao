// ============================================================
// Projeto: Laboratório de Testes de Algoritmos de Ordenação
// Autor: Ryan Lucca Marques Pereira
// Objetivo: Testar e comparar o desempenho de algoritmos de ordenação
// ============================================================

#include <stdio.h>

// ============================================================
// BUBBLE SORT - ORDENAÇÃO POR BOLHA
// ============================================================

void bubbleSort(int vetor[], int tamanho) {
    int i, j, temp;

    // Percorre o vetor várias vezes
    for (i = 0; i < tamanho - 1; i++) {

        // Compara os valores vizinhos
        for (j = 0; j < tamanho - 1 - i; j++) {

            // Verifica se o valor atual é maior que o próximo
            if (vetor[j] > vetor[j + 1]) {

                // Troca os dois valores
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}


// ============================================================
// INSERTION SORT - ORDENAÇÃO POR INSERÇÃO
// ============================================================

void insertionSort(int vetor[], int tamanho) {
    int i, j, chave;

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


// ============================================================
// SELECTION SORT - ORDENAÇÃO POR SELEÇÃO
// ============================================================

void selectionSort(int vetor[], int tamanho) {
    int i, j, menor, temp;

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


// ============================================================
// MERGE SORT - ORDENAÇÃO POR MESCLAGEM
// ============================================================

// Função responsável por intercalar duas partes ordenadas
void intercalar(int vetor[], int esquerda, int meio, int direita) {

    int i, j, k;

    // Calcula o tamanho das duas partes
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    // Cria vetores temporários
    int V_Esquerda[n1];
    int V_Direita[n2];

    // Copia a primeira metade
    for (i = 0; i < n1; i++) {
        V_Esquerda[i] = vetor[esquerda + i];
    }

    // Copia a segunda metade
    for (j = 0; j < n2; j++) {
        V_Direita[j] = vetor[meio + 1 + j];
    }

    // Inicializa os índices
    i = 0;
    j = 0;
    k = esquerda;

    // Intercala as duas partes
    while (i < n1 && j < n2) {

        if (V_Esquerda[i] <= V_Direita[j]) {

            vetor[k] = V_Esquerda[i];
            i++;

        } else {

            vetor[k] = V_Direita[j];
            j++;
        }

        k++;
    }

    // Copia os elementos restantes da esquerda
    while (i < n1) {

        vetor[k] = V_Esquerda[i];

        i++;
        k++;
    }

    // Copia os elementos restantes da direita
    while (j < n2) {

        vetor[k] = V_Direita[j];

        j++;
        k++;
    }
}


// Função recursiva do Merge Sort
void mergeSort(int vetor[], int esquerda, int direita) {

    // Verifica se ainda é possível dividir o vetor
    if (esquerda < direita) {

        // Calcula o ponto médio
        int meio = esquerda + (direita - esquerda) / 2;

        // Ordena recursivamente a primeira metade
        mergeSort(vetor, esquerda, meio);

        // Ordena recursivamente a segunda metade
        mergeSort(vetor, meio + 1, direita);

        // Intercala as duas metades
        intercalar(vetor, esquerda, meio, direita);
    }
}


// ============================================================
// QUICK SORT - ORDENAÇÃO RÁPIDA
// ============================================================

// Função responsável por particionar o vetor
int particionar(int vetor[], int inicio, int fim) {

    // Define o primeiro elemento como pivô
    int pivot = vetor[inicio];

    // i começa depois do pivô
    int i = inicio + 1;

    // j começa no final do vetor
    int j = fim;

    // Continua enquanto os índices não se cruzarem
    while (i <= j) {

        // Procura um elemento maior ou igual ao pivô
        while (i <= fim && vetor[i] < pivot) {
            i++;
        }

        // Procura um elemento menor que o pivô
        while (j > inicio && vetor[j] >= pivot) {
            j--;
        }

        // Se os índices não se cruzaram, troca os elementos
        if (i < j) {

            int temp = vetor[i];

            vetor[i] = vetor[j];

            vetor[j] = temp;
        }
    }

    // Coloca o pivô na posição correta
    int temp = vetor[inicio];

    vetor[inicio] = vetor[j];

    vetor[j] = temp;

    // Retorna a posição final do pivô
    return j;
}


// Função recursiva do Quick Sort
void quickSort(int vetor[], int inicio, int fim) {

    // Verifica se ainda existe mais de um elemento
    if (inicio < fim) {

        // Particiona o vetor e encontra a posição do pivô
        int pivot = particionar(vetor, inicio, fim);

        // Ordena a parte esquerda
        quickSort(vetor, inicio, pivot - 1);

        // Ordena a parte direita
        quickSort(vetor, pivot + 1, fim);
    }
}


// ============================================================
// FUNÇÃO PARA MOSTRAR O VETOR
// ============================================================

void imprimirVetor(int vetor[], int tamanho) {

    int i;

    for (i = 0; i < tamanho; i++) {

        printf("%d ", vetor[i]);
    }

    printf("\n");
}


// ============================================================
// PROGRAMA PRINCIPAL
// ============================================================

int main() {

    int tamanho;
    int opcao;

    // Exibe o título principal
    printf("\n=== LABORATORIO DE TESTES DE ALGORITMOS DE ORDENACAO ===\n\n");

    // Pede o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // Cria o vetor com o tamanho informado
    int vetor[tamanho];

    // Gera os números do vetor
    for (int i = 0; i < tamanho; i++) {

        vetor[i] = i;
    }

    // Mostra o vetor antes da ordenação
    printf("\nVetor original:\n");
    imprimirVetor(vetor, tamanho);

    // ========================================================
    // MENU
    // ========================================================

    printf("\nSelecao de algoritmos:\n\n");

    printf("1 - Bolha\n");
    printf("2 - Insercao\n");
    printf("3 - Selecao\n");
    printf("4 - Merge\n");
    printf("5 - Quick\n");

    // Pede a opção
    printf("\nEscolha um algoritmo: ");
    scanf("%d", &opcao);

    // ========================================================
    // EXECUÇÃO DO ALGORITMO ESCOLHIDO
    // ========================================================

    if (opcao == 1) {

        bubbleSort(vetor, tamanho);

        printf("\nBubble Sort executado.\n");
    }

    else if (opcao == 2) {

        insertionSort(vetor, tamanho);

        printf("\nInsertion Sort executado.\n");
    }

    else if (opcao == 3) {

        selectionSort(vetor, tamanho);

        printf("\nSelection Sort executado.\n");
    }

    else if (opcao == 4) {

        mergeSort(vetor, 0, tamanho - 1);

        printf("\nMerge Sort executado.\n");
    }

    else if (opcao == 5) {

        quickSort(vetor, 0, tamanho - 1);

        printf("\nQuick Sort executado.\n");
    }

    else {

        printf("\nOpcao invalida.\n");

        return 1;
    }

    // ========================================================
    // MOSTRA O VETOR ORDENADO
    // ========================================================

    printf("\nVetor ordenado:\n");

    imprimirVetor(vetor, tamanho);

    return 0;
}