#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct TipoItem{
    int num;
    //outros campos
}TipoItem;

typedef struct Celula{
    TipoItem Item;
    struct Celula* Prox;
}Celula;

typedef struct{
    struct Celula* Primeiro;
    struct Celula* Ultimo;
}TipoLista;
