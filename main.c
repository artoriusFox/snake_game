#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>
#include "classes/lista.h"
#include "classes/corpo.h"
#include "classes/console.h"

struct personagem {
    int x,y;
    char avatar;
};

char tecla, tem_tecla;
int tempo,tamanho,statusJogo,pontuacao;
time_t inicial, atual;

typedef struct personagem Personagem;
Personagem p,pOld;

Lista* mapa;
Corpo* corpo;

void inicializaJogo() {
    tecla=NULL;
    tamanho = 0;
    statusJogo= EM_JOGO;
    pontuacao = 0;
    tempo = 0;
    tem_tecla = TECLA_ESPERA;

    time(&inicial);

    p.x = 5;
    p.y = 5;
    pOld.x = 0;
    pOld.y = 0;

    p.avatar = 'o';
    mapa = lst_cria();
    corpo = corpo_cria();

    criaMapa();
    for (int i =1;i<=NUMERO_INICIAL_FRUTAS;i++ ){
        insereFrutaAleatoria();
    }
    lst_imprime(mapa);
}

void insereFrutaAleatoria(){
    int randonFruta = 2+ rand() % (5-2);
    int x,y;
    do{
     x = 3 + rand() % (19-2);
     y = 2 + rand() % (59-2);
    }while (verificaGeracaoFruta(x,y) == 0);

    gerarFruta(x,y,randonFruta);
    lst_imprime(mapa);

}
void gerarFruta(int x,int y,int fruta){
    switch (fruta){
    case FRUTA1:
         mapa = lst_insere(mapa, y, x,'o',COLOR_GREEN,COLOR_BLACK,fruta);
         break;
    case FRUTA2:
         mapa = lst_insere(mapa, y, x,'O',COLOR_RED,COLOR_BLACK,fruta);
         break;
    case FRUTA3:
         mapa = lst_insere(mapa, y, x,'@',COLOR_MAGENTA,COLOR_BLACK,fruta);
         break;
    }
}

int verificaGeracaoFruta(int x, int y){
    if (lst_temElemento(mapa,x,y) == NADA || corpo_temElemento(corpo,x,y) != 1)
        return 1;
    return 0;
}

void criaMapa(){
    criaMapaLinhaHorizontal(2,60,2);
    criaMapaLinhaHorizontal(2,60,20);
    criaMapaLinhaVertical(2,20,2);
    criaMapaLinhaVertical(2,20,60);

    criaMapaLinhaHorizontal(10,15,6);
    criaMapaLinhaHorizontal(10,15,7);
    criaMapaLinhaHorizontal(10,15,8);

    criaMapaLinhaVertical(13,20,40);
    criaMapaLinhaVertical(13,20,41);
    criaMapaLinhaHorizontal(30,40,13);
}
void criaMapaLinhaHorizontal(int inicio,int fim,int coluna){
    for (inicio; inicio <= fim;inicio++){
        mapa = lst_insere(mapa, inicio, coluna,(char)219,COLOR_YELLOW,COLOR_YELLOW,PAREDE);
    }
}

void criaMapaLinhaVertical (int inicio,int fim,int linha){
    for (inicio; inicio <= fim;inicio++){
        mapa = lst_insere(mapa, linha , inicio,(char)219,COLOR_YELLOW,COLOR_YELLOW,PAREDE);
    }
}
void apagaRastro(){
    gotoxy(pOld.x,pOld.y);
    setBackgroundColor(COLOR_BLACK);
    printf("%c",' ');
}

void controle() {
    time(&atual);
    tempo = atual - inicial;
    if(tem_tecla == TECLA_PRESSIONADA ) {
        pOld=p;
        switch(tecla) {
        case TECLA_CIMA:
            p.y--;
            p.avatar='^';
            break;
        case TECLA_BAIXO:
            p.y++;
            p.avatar='v';
            break;
        case TECLA_ESQUERDA:
            p.x--;
             p.avatar='<';
            break;
        case TECLA_DIREITA:
            p.x++;
            p.avatar='>';
            break;
        case TECLA_ESC:
            exit(0);
            break;
        }
    }
}

void leTeclado() {
    if(kbhit()) {
        tecla = getch();
        tem_tecla = TECLA_PRESSIONADA;
    }
}

void atualizaMapa() {
    apagaRastro();
    desenhaPersonagem();
    desenharInfo(pontuacao,tamanho,tempo);
    }

void desenhaPersonagem(){
    gotoxy(p.x,p.y);
    setColor(COLOR_RED);
    setBackgroundColor(COLOR_GREEN);
    printf("%c", p.avatar);

    colisao();
    apagarUltimo(corpo);
    corpo=corpo_insere(corpo,pOld.x,pOld.y);
}

void colisao(){
    if (lst_temElemento(mapa,p.x,p.y) == PAREDE){
        morreu();
    }else if (lst_temElemento(mapa,p.x,p.y) == FRUTA1){
        pegaFruta(100,p.x,p.y);
    }else if (lst_temElemento(mapa,p.x,p.y) == FRUTA2){
        pegaFruta(150,p.x,p.y);
    }else if (lst_temElemento(mapa,p.x,p.y) == FRUTA3){
        pegaFruta(300,p.x,p.y);
    }else if(corpo_temElemento(corpo,p.x,p.y) == 1 ){
       morreu();
    }
}

void pegaFruta(int valor,int x, int y){
    mapa =lst_retira(mapa,x,y);
    pontuacao = pontuacao + valor;
    tamanho++;

    corpo = corpo_insere(corpo,pOld.x,pOld.y);
    insereFrutaAleatoria();
}

void morreu(){
    statusJogo=MORTO;

    criaTelaMorte(tamanho,pontuacao);
    main();
}

int main() {
    setWindow(100,25);
    SetConsoleTitle("Snake_C");
    inicializaJogo();
    updateGame();

}

void updateGame(){
    while(statusJogo == EM_JOGO) {
        leTeclado();
        controle();
        atualizaMapa();
        usleep(100000 - (pontuacao*10));
    }
}


