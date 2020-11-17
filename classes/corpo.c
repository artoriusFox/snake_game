#include <stdio.h>
#include <stdlib.h>
#include "corpo.h"
#include "console.h"

struct corpo{
    int x,y;
    int status;
    struct Corpo* prox;
    };
Corpo* corpo_cria() {
    return NULL;
}

Corpo* corpo_insere(Corpo* l, int x, int y) {
    Corpo* novo = (Corpo*) malloc(sizeof(Corpo));
    novo->x = x;
    novo->y = y;
    novo->prox=l;
    novo->status=1;
    imprime(x,y);
    return novo;
}

int corpo_temElemento(Corpo* l, int x, int y) {
    Corpo* p;
    for(p = l; p != NULL; p = p->prox) {
        if ((p->x == x) && (p->y == y)){
            return p->status;
        }
    }
    return 0;
}

void imprime(x,y){
gotoxy(x,y);
int r =  1 + rand() % (14);
setBackgroundColor(r);
printf("%c",' ');
}

void apagarUltimo(Corpo* c){
    setBackgroundColor(COLOR_BLACK);
    Corpo* p;
    for(p = c; p != NULL; p = p->prox) {
        Corpo* proxCorpo;
        proxCorpo=p->prox;
        if(p->prox==NULL || proxCorpo->status==2){
            gotoxy(p->x,p->y);
            printf("%c",' ');
            p->status=2;
            return;
        }
    }
}
