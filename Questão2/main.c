#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"
#include "arvore.h"

void escolher(int escolha){
    switch(escolha){
        case 1:;
            node *PILHAS = (node *)malloc(sizeof(node));
            PILHAS->prox = NULL;
            int tam_pilha = 0;
            escolheu_pl(PILHAS, tam_pilha);
            break;
        case 2:;
            No *FILA = (No*)malloc(sizeof(No));
            FILA->prox = NULL;
            int tam_fila = 0;
            escolheu_fl(FILA, tam_fila);
            break;
        case 3:
            Arv arv;
            arv.raiz = NULL;
            Nos *raiz = NULL;
            escolheu_arvore(raiz);
            break;
        default:
            printf("Escolha uma opção!");
    }
};
int main(){
    int escolha;
    printf("Opção -> 1.pilha! \n");
    printf("Opção -> 2.fila! \n");
    printf("Opção -> 3.arvore! \n");
    scanf("%d", &escolha);
    escolher(escolha);
}