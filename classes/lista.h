typedef struct lista Lista;
Lista* lst_cria();
Lista* lst_insere(Lista* l, int x, int y, char simbolo,int cor,int corFundo, int tipo);
void lst_imprime(Lista* l);
int lst_temElemento(Lista* l, int x, int y);
Lista* lst_retira(Lista* l, int x, int y);
