/*Arquivo destinado às funções que
serão utilizadas nesse projeto.*/

//Criação da struct que origina a lista:

struct estrutura{
    int num;
    struct estrutura *prox;
};

//Define o tipo lista_ecadeada:

typedef struct estrutura lista_encadeada;

//Verifica se a lista está vazia:

bool verifica_vazia(lista_encadeada *lista){
    if(lista->prox == NULL){
        return true;
    }else{
        return false;
    }
}

//Função que inicia lista:

void inicia(lista_encadeada *lista){
    lista->prox = NULL;
}

//Limpa elementos da lista e reinicia ela:

void limpa(lista_encadeada *lista){
    if(!verifica_vazia(lista)){
        lista_encadeada *proximo, *atual;
        atual = lista->prox;
        while(atual != NULL){
            proximo = atual->prox;
            free(atual);
            atual = proximo;
        }
    }
    inicia(lista);
}

//Imprime os elementos da lista:

void imprime_lista(lista_encadeada *lista){
    if(verifica_vazia(lista)){
        printf("Lista vazia!\n\n");
    }else{
        printf("Elementos da lista:\n\n");
        lista_encadeada *aux = lista->prox;
        while(aux != NULL){
            printf("%d ", aux->num);
            aux = aux->prox;
        }
        printf("\n\n");
    }
}

//Adiciona elemento no início da lista:

void adiciona_inicio(lista_encadeada *lista){
    lista_encadeada *aux = (lista_encadeada*) malloc(sizeof(lista_encadeada));
    if(!aux){
        printf("Sem memória sufuciente disponível!\n");
    }else{
        printf("Digite um número inteiro para ser inserido no início da lista: ");
        scanf("%d", &aux->num);
        lista_encadeada *antiga = lista->prox;
        lista->prox = aux;
        aux->prox = antiga;
        printf("\nValor adicionado com sucesso!\n\n");
    }
}

//Adiciona elemento no final da lista:

void adiciona_final(lista_encadeada *lista){
    lista_encadeada *aux = (lista_encadeada*) malloc(sizeof(lista_encadeada));
    if(!aux){
        printf("Sem memória sufuciente disponível!\n");
    }else{
        printf("Digite um número inteiro para ser inserido no fim da lista: ");
        scanf("%d", &aux->num);
        aux->prox = NULL;
        if(verifica_vazia(lista)){
            lista->prox = aux;
        }else{
            lista_encadeada *aux_2 = lista->prox;
            while(aux_2->prox != NULL){
                aux_2 = aux_2->prox;
            }
            aux_2->prox = aux;
        }
        printf("\nValor adicionado com sucesso!\n\n");
    }
}
