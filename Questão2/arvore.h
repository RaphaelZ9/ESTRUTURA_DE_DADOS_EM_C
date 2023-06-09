typedef struct nos{
    int chave;
    struct nos *esquerda, *direita;
}Nos;
typedef struct arv{
    Nos *raiz;
    int tam;
}Arv;
Nos* inserir(Nos *raiz, int valor){
    if(raiz == NULL){
        Nos *novo = (Nos*)malloc(sizeof(Nos));
        novo->chave = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    else{
        if (valor < raiz->chave){
            raiz->esquerda = inserir(raiz->esquerda, valor);
        }
        if (valor > raiz->chave){
            raiz->direita = inserir(raiz->direita, valor);
        }
        return raiz;
    }
}
void imprime(Nos *raiz){
    if(raiz != NULL){
        imprime(raiz->esquerda);
        printf("%d ", raiz->chave);
        imprime(raiz->direita);
    }
}

void imprimeInverso(Nos *raiz){ 
    if(raiz != NULL){
        imprimeInverso(raiz->direita);
        printf("%d ", raiz->chave);
        imprimeInverso(raiz->esquerda);
    }
}
Nos* remover(Nos *raiz, int item){
    if(raiz == NULL){
        printf("\n Valor inexistente! \n");
        return NULL;
    }
    else{
        if(raiz->chave == item){
            if(raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                return NULL;
            }
            else{
                if (raiz->esquerda == NULL || raiz->direita == NULL){
                    Nos *aux;
                    if(raiz->esquerda == NULL){
                        aux = raiz->direita;
                    }
                    else{
                        aux = raiz->esquerda;
                    }
                    free(raiz);
                    return aux;
                }
                else{
                    Nos *aux = raiz->esquerda;
                    while(aux->direita != NULL){
                        aux = aux->direita;
                    }
                    raiz->chave = aux->chave;
                    aux->chave = item;
                    raiz->esquerda = remover(raiz->esquerda, item);
                    return raiz;
                }
            }
        }
        else{
            if(item < raiz->chave){
                raiz->esquerda = remover(raiz->esquerda, item);
            }
            else{
                raiz->direita = remover(raiz->direita, item);
            }
            return raiz;
        }
    }
}
int maior(Nos* raiz){ 
    if (raiz == NULL){
        printf("\n Árvore vazia \n");
    }
    if(raiz->direita == NULL){
        return raiz->chave;
    }
    return maior(raiz->direita);
}
Nos* buscar(Nos* raiz, int valor){ 
    if(raiz == NULL || raiz->chave == valor){
        return raiz;
    }
    if(valor < raiz->chave){
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}
void escolheu_arvore(Nos *raiz){
    printf("\n Escolha a operação de Árvore \n");
    printf("1-Inserir \n 2-Remover \n 3-Imprimir \n 4-Imprimir invertido \n 5-Buscar \n 6-Imprimir maior \n 7-Sair \n:");
    int escolha_arvore;
    scanf("%d", &escolha_arvore);
    switch(escolha_arvore){
        case 1:
            int a;
            printf("Digite um número \n:");
            scanf("%d", &a);
            raiz = inserir(raiz, a);
            escolheu_arvore(raiz);
            break;
        case 2:
            int b;
            printf("\n Digite um número para remover \n: ");
            scanf("%d", &b);
            raiz = remover(raiz, b);
            escolheu_arvore(raiz);
            break;
        case 3:
            imprime(raiz);
            escolheu_arvore(raiz);
            break;
        case 4:
            imprimeInverso(raiz);
            escolheu_arvore(raiz);
            break;
        case 5:
            int c;
            printf("\n Digite um número para buscar \n->");
            scanf("%d", &c);
            Nos* resultado = buscar(raiz, c);
            if (resultado == NULL) {
                printf("\n Número não existe! \n");
            } else {
                printf("\n Número existente! \n");
            }
            escolheu_arvore(raiz);
            break;
        case 6:
            printf(" O maior elemento é: %d\n", maior(raiz));
            escolheu_arvore(raiz);
            break;
        case 7:
            break;
        default:
            printf("Digite corretamente!");
            escolheu_arvore(raiz);
            break;
    }
}