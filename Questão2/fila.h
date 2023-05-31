typedef struct No{
    int conteudo;
    struct No *prox;
}No;

int EMPTY(No *FILA){
    if(FILA->prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

void ENQUEUE(No *FILA, int tam){
    No *novo = (No*)malloc(sizeof(No));
    novo->prox = NULL;
    
    printf("Digite uma fila: ");
    scanf("%d", &novo->conteudo);
    
    if(EMPTY(FILA)){
        FILA->prox = novo;
    }else{
        No *tmp = FILA->prox;
        while(tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
    tam++;
}

void DEQUEUE(No *FILA, int tam){
    if(FILA->prox == NULL){
        printf("\n Fila vazia! \n");
        return;
    }
    else{
        No *tmp = FILA->prox;
        FILA->prox = tmp->prox;
        tam--;
        free(tmp);
    }
}

void LIMPAR_FILA(No *FILA, int tam){
    while(FILA->prox != NULL){
        No *tmp = FILA->prox;
        FILA->prox = tmp->prox;
        free(tmp);
    }
    tam = 0;
}

void MAIOR_ELEMENTO(No *FILA, int tam){
    if(EMPTY(FILA)){
        printf("\n Fila vazia! \n");
        return;
    }
    int maior = FILA->prox->conteudo;
    No *tmp = FILA->prox->prox;
    while(tmp != NULL){
        if(tmp->conteudo > maior){
            maior = tmp->conteudo;
        }
        tmp = tmp->prox;
    }
    printf("\n O maior item na fila é: %d\n", maior);
}

void MENOR_ELEMENTO(No *FILA, int tam){
    if(EMPTY(FILA)){
        printf("\n Fila vazia! \n");
        return;
    }
    int menor = FILA->prox->conteudo;
    No *tmp = FILA->prox->prox;
    while(tmp != NULL){
        if(tmp->conteudo < menor){
            menor = tmp->conteudo;
        }
        tmp = tmp->prox;
    }
    printf("\n O menor item na fila é: %d\n", menor);
}

void IMPRIMIR(No *FILA){
    if(EMPTY(FILA)){
        printf("\n Fila vazia! \n");
        return;
    }
    printf("\n  Lista de elementos na fila  \n");
    No *tmp = FILA->prox;
    while (tmp != NULL){
        printf(" %d ", tmp->conteudo);
        tmp = tmp->prox;
    }
}

void escolheu_fl(No *FILA, int tam){
    printf("\n  Escolha a operação de Fila  \n");
    printf("1-Enqueue \n 2-Dequeue \n 3-Imprimir \n 4-Limpar \n 5- Maior elemento \n 6-Menor elemento \n 7-Sair \n:");
    int escolha_fl;
    scanf("%d", &escolha_fl);
    switch(escolha_fl){
        case 1:
            ENQUEUE(FILA, tam);
            escolheu_fl(FILA, tam);
        case 2:
            DEQUEUE(FILA, tam);
            escolheu_fl(FILA, tam);
        case 3:
            IMPRIMIR(FILA);
            escolheu_fl(FILA, tam);
        case 4:
            LIMPAR_FILA(FILA, tam);
            escolheu_fl(FILA, tam);
        case 5:
            MAIOR_ELEMENTO(FILA, tam);
            escolheu_fl(FILA, tam);
        case 6:
            MENOR_ELEMENTO(FILA, tam);
            escolheu_fl(FILA, tam);
        case 7:
            break;
        default:
            printf("Digite corretamente! ");
    }
}