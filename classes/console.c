#include <windows.h>
#include "console.h"
void setWindow(int Width, int Height) {
    COORD coord;
    coord.X = Width;
    coord.Y = Height;

    SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(Handle, coord);
    SetConsoleWindowInfo(Handle, TRUE, &Rect);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setBackgroundColor(int c) {
#if defined(_WIN32) && !defined(RLUTIL_USE_ANSI)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(hConsole, &csbi);

    SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xFF0F) | (((WORD)c) << 4));
#else
    RLUTIL_PRINT(getANSIBackgroundColor(c));
#endif
}

void setColor(int ForgC) {
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void criaTelaMorte(int tamanho,int pontuacao){
    setBackgroundColor(COLOR_BLACK);
    system("cls");
    gotoxy (45,7);
    printf("VOCE MORREU!");
    usleep(500000);
    gotoxy (42,8);
    usleep(500000);
    printf("SEU TAMANHO FOI: %d", tamanho);
    gotoxy (40,9);
    usleep(500000);
    printf("E SUA PONTUACAO FOI: %d", pontuacao);
    gotoxy (28,11);
    usleep(1000000);
    printf("pressione qualquer outra tecla para recomecar!");
    system("pause > NULL");
    system("cls");
}
void desenharInfo(int pontuacao,int tamanho,int tempo){
    gotoxy (62,2);
    printf ("      __..  ..__..  ..___    __      ");
    gotoxy (62,3);
    printf ("     (__ |\\ |[__]|_/ [__    /  `     ");
    gotoxy (62,4);
    printf("     .__)| \\||  ||  \\[___   \\__.     ");
    gotoxy (62,5);
    printf("                                     ");
    setColor(COLOR_YELLOW);
    setBackgroundColor(COLOR_BLACK);
    gotoxy(80,20);
    printf("Tempo de jogo: %d    ", tempo);
    setBackgroundColor(COLOR_BLACK);
    setColor(COLOR_WHITE);
    gotoxy(0,23);
    printf("                 ");
    gotoxy(0,23);
    gotoxy(64,18);
    printf("-----------------------------------");
    gotoxy(64,8);
    printf("|O objetivo do jogo e: coletar as |");
    gotoxy(64,9);
    printf("|frutas e evitar bater nas paredes|");
    gotoxy(64,10);
    printf("|ou em si mesmo                   |");
    gotoxy(64,11);
    printf("|           BOA SORTE!            |");
    gotoxy(64,12);
    printf("|                                 |");
    gotoxy(64,13);
    printf("|");
    setColor(COLOR_GREEN);
    printf("(o) vale 100 pontos              ");
    setColor(COLOR_WHITE);
    printf("|");
    gotoxy(64,14);
    printf("|");
    setColor(COLOR_RED);
    printf("(O) vale 150 pontos              ");
    setColor(COLOR_WHITE);
    printf("|");
    gotoxy(64,15);
    printf("|");
    setColor(COLOR_MAGENTA);
    printf("(@) vale 300 pontos              ");
    setColor(COLOR_WHITE);
    printf("|");
    gotoxy(64,16);
    printf("|                                 |");
    gotoxy(64,17);
    printf("|Para Sair pressione ESC.         |");
    gotoxy(64,7);
    printf("-----------------------------------");
    gotoxy(62,19);
    printf("Pontos : %d    ", pontuacao);
    gotoxy(62,20);
    printf("Tamanho : %d    ", tamanho);
}


