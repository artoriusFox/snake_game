#define TECLA_CIMA 72
#define TECLA_BAIXO 80
#define TECLA_ESQUERDA 75
#define TECLA_DIREITA 77
#define TECLA_ENTER 13
#define TECLA_ESPACO 32
#define TECLA_ESC 27
#define TECLA_s 115
#define TECLA_S 83
#define TECLA_n 110
#define TECLA_N 78
#define NUMERO_INICIAL_FRUTAS 10

enum {
    COLOR_BLACK,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_CYAN,
    COLOR_RED,
    COLOR_MAGENTA,
    COLOR_BROWN,
    COLOR_GREY,
    COLOR_DARKGREY,
    COLOR_LIGHTBLUE,
    COLOR_LIGHTGREEN,
    COLOR_LIGHTCYAN,
    COLOR_LIGHTRED,
    COLOR_LIGHTMAGENTA,
    COLOR_YELLOW,
    COLOR_WHITE
};

enum {
    NADA,
    PAREDE,
    FRUTA1,
    FRUTA2,
    FRUTA3
};

enum {
    EM_JOGO,
    MORTO
};

enum {
    TECLA_PRESSIONADA,
    TECLA_ESPERA
};

void setWindow(int Width, int Height);
void gotoxy(int x, int y);
void setBackgroundColor(int c);
void setColor(int ForgC);
void criaTelaMorte(int tamanho,int pontuacao);
void desenharInfo(int pontuacao,int tamanho,int tempo);
