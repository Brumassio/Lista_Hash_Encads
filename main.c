#include "tools.c"

int main(){
    TipoLista *li[10];
    Cria_Listas_Encads(li,10);
    TipoItem x;
    x.num = 10;
    Insere_Hash_Lista_Encads(x.num,li,10);
    x.num = 11;
    Insere_Hash_Lista_Encads(x.num,li,10);
    x.num = 12;
    Insere_Hash_Lista_Encads(x.num,li,10);
    x.num = 13;
    Insere_Hash_Lista_Encads(x.num,li,10);
    x.num = 14;
    Insere_Hash_Lista_Encads(x.num,li,10);
    x.num = 15;
    Insere_Hash_Lista_Encads(x.num,li,10);
    x.num = 16;
    Insere_Hash_Lista_Encads(x.num,li,10);
    x.num = 17;
    Insere_Hash_Lista_Encads(x.num,li,10);
    x.num = 18;
    Insere_Hash_Lista_Encads(x.num,li,10);
    x.num = 19;
    Insere_Hash_Lista_Encads(x.num,li,10);
    x.num = 22;
    Insere_Hash_Lista_Encads(x.num,li,10);
    Imprimir_Hash_Encadeado(&li,10);
    Buscar_Hash_Encadeado(li,12,10);
    Buscar_Hash_Encadeado(li,22,10);
    Exclusao_Elemento_Hash_Encadeado(li,12,10);
    Exclusao_Elemento_Hash_Encadeado(li,22,10);
    Exclusao_Elemento_Hash_Encadeado(li,32,10);
    Imprimir_Hash_Encadeado(&li,10);
    Libera_Hash_Encadeado(li,10);
    Imprimir_Hash_Encadeado(&li,10);
    return 0;
}
