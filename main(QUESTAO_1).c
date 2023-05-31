#include <stdio.h>

void imprimirVetor(int vetor[], int valor) {
    for (int i = 0; i < valor; i++) {
        printf("%d ", vetor[i]);
    }
}
void bubbleSort(int vetor[], int valor) {
    int i, j, temp;
    for (i = 0; i < valor - 1; i++) {
        for (j = 0; j < valor - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}
void insertionSort(int vetor[], int valor) {
    int i, chave, j;
    for (i = 1; i < valor; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}
int main() {
    int valor, opcao;

    printf("Digite o valor do vetor: ");
    scanf("%d", &valor);

    int vetor[valor];

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < valor; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("\nEscolha o método de ordenacão:\n");
    printf("1-> Bubble Sort \n");
    printf("2-> InsertionSort \n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            bubbleSort(vetor, valor);
            printf("\n Vetor ordenado pela opcão 1: ");
            imprimirVetor(vetor, valor);
            break;

        case 2:
            insertionSort(vetor, valor);
            printf("\n Vetor ordenado pela opcão 2: ");
            imprimirVetor(vetor, valor);
            break;

        default:
            printf("Opção errada.\n");
            break;
    }
    return 0;
}
