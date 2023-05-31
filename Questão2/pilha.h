struct Node{
    int item;
    struct Node *prox;
};

typedef struct Node node;

int vazia(node *PILHAS){
    if(PILHAS->prox == NULL){
        return 1;
    }else{
        return 0;
    }
}
void PUSH(node *PILHAS, int tam){
    node *novo = (node *)malloc(sizeof(node));
    novo->prox = NULL;
    printf("Digite uma pilha: ");
    scanf("%d", &novo->item);
    
    if(vazia(PILHAS)){
        PILHAS->prox = novo;
    }else{
        node *temp = PILHAS->prox;
        while(temp->prox != NULL){
            temp = temp->prox;
        }
        temp->prox = novo;
    }
    tam++;
}
void IMPRIME(node *PILHAS, int tam){
    if(vazia(PILHAS)){
        printf("Pilha vazia! \n");
        return;
    }else{
        node *temp;
        temp = PILHAS->prox;
        printf("\nPilha: ");
        while(temp != NULL){
            printf("%3d", temp->item);
            temp = temp->prox;
            tam++;
        }
    }
    printf("\n Quantidade de itens na Pilha: %d", tam);
    printf("\n");
}
void POP(node *PILHAS, int tam){
    if(PILHAS->prox == NULL){
        printf("A pilha está vazia!\n\n");
        return;
    }
    else{
        node *ultimo = PILHAS->prox;
        node *penultimo = PILHAS;
        
        while(ultimo->prox != NULL){
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        free(ultimo);
        penultimo->prox = NULL;
        tam--;
    }
}
void LIMPAR(node *PILHAS, int tam){
    node *atual = PILHAS->prox;
    node *proximo;
    while(atual != NULL){
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    PILHAS->prox = NULL;
    tam = 0;
}
void TOPO(node *PILHAS){
    if(PILHAS->prox == NULL){
        printf("A pilha está vazia!\n");
    } 
    else{
        node *atual = PILHAS->prox;
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        printf("Topo da Pilha: %d\n", atual->item);
    }
}
void escolheu_pl(node *PILHAS, int tam){
    printf("\n Escolha a operação de Pilha \n");
    printf("1-Empilha \n 2-Desempilha \n 3-Imprimi \n 4-Limpar  \n 5-Imprimir Topo  \n 6-Sair \n:");
    int escolha_pl;
    scanf("%d", &escolha_pl);
    switch(escolha_pl){
        case 1:
            PUSH(PILHAS, tam);
            escolheu_pl(PILHAS, tam);
            break;
        case 2:
            POP(PILHAS, tam);
            escolheu_pl(PILHAS, tam);
            break;
        case 3:
            IMPRIME(PILHAS, tam);
            escolheu_pl(PILHAS, tam);
            break;
        case 4:
            LIMPAR(PILHAS, tam);
            escolheu_pl(PILHAS, tam);
            break;
        case 5:
            TOPO(PILHAS);
            escolheu_pl(PILHAS, tam);
            break;
        case 6:
            break;
        default:
            printf("Digite corretamente! ");
    }
}