#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "console.h"

struct lista {
    int x,y;
    char simbolo;
    int cor,corFundo;
    int tipo;
    struct lista* prox;
};

Lista* lst_cria() {
    return NULL;
}

Lista* lst_insere(Lista* l, int x, int y, char simbolo,int cor,int corFundo, int tipo) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->x = x;
    novo->y = y;
    novo->simbolo = simbolo;
    novo->prox = l;
    novo->cor = cor;
    novo->corFundo = corFundo;
    novo->tipo = tipo;
    return novo;
}

void lst_imprime(Lista* l) {
    Lista* p;
    for(p = l; p != NULL; p = p->prox) {
        setColor(p->cor);
        setBackgroundColor(p->corFundo);
        gotoxy(p->x, p->y);
        printf("%c", p->simbolo);

    }
}

int lst_temElemento(Lista* l, int x, int y) {
    Lista* p;
    for(p = l; p != NULL; p = p->prox) {
        if ((p->x == x) && (p->y == y)){
            return p->tipo;
        }
    }
    return 0;
}

Lista* lst_retira(Lista* l, int x, int y) {
    Lista* ant = NULL;
    Lista* atual = l;
    while(atual != NULL && (atual->x != x || atual->y != y)) {
        ant = atual;
        atual = atual->prox;
    }
    if(atual == NULL)
        return l;

    if(ant == NULL)
        l = atual->prox;
    else
        ant->prox = atual->prox;
    free(atual);
    return l;
}
