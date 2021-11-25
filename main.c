#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "funcoes.h"

int main(void){
    setlocale(LC_ALL, "portuguese");
    int opc;
    bool sai_do_loop = true;
    lista_encadeada *lista;
    inicia(lista);
    while(sai_do_loop){
        printf("Lista de opções:\n\n");
        printf("Opção 1: limpa a lista;\n");
        printf("Opção 2: imprime a lista;\n");
        printf("Opção 3: adiciona elemento no início da lista;\n");
        printf("Opção 4: adiciona elemento no fim da lista;\n");
        printf("Opção 5: encerra o algoritmo;\n\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opc);
        switch(opc){
            case 1:
                system("clear");
                limpa(lista);
                printf("Lista vazia!\n\n");
                break;
            case 2:
                system("clear");
                imprime_lista(lista);
                break;
            case 3:
                system("clear");
                adiciona_inicio(lista);
                break;
            case 4:
                system("clear");
                adiciona_final(lista);
                break;
            case 5:
                system("clear");
                printf("Fim do algoritmo!\n");
                sai_do_loop = false;
                break;
            default:
                system("clear");
                printf("Opção inválida! Tente novamente!\n\n");
                break;
            }
    }
    return 0;
}
