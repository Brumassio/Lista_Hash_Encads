#include "item.h"
void Imprime_Lista_Encadeada(TipoLista Lista){
    Celula* Aux;
    Aux = Lista.Primeiro -> Prox;
    while (Aux != NULL){
        printf ("%d;", Aux->Item.num);
        Aux=Aux->Prox;
    }
}

void Imprimir_Hash_Encadeado(TipoLista *vetor, int tamanho){
    printf("\n");
    for(int i = 0; i<tamanho; i++){
        printf("\nposicao %d [", i);
        Imprime_Lista_Encadeada(vetor[i]);
        printf("]", i);
    }
}

void CLEVazia (TipoLista *Lista){
    Lista -> Primeiro = (Celula*) malloc(sizeof(Celula));
    Lista -> Ultimo = Lista -> Primeiro;
    Lista -> Primeiro -> Prox = NULL;
}

void Libera_Lista_Encadeada(TipoLista *Lista,int tamanho){
    Celula* Aux;
    Aux = Lista->Primeiro;
    int cont =0;
    while (Aux!= NULL){
        Celula* Aux2;
        Aux2 = Aux;
        Aux = Aux->Prox;
        free(Aux2);
    }
    CLEVazia(Lista);
}

void Libera_Hash_Encadeado(TipoLista *vetor, int tamanho){
    printf("\n");
    for(int i=0;i<tamanho;i++){
        Libera_Lista_Encadeada(&vetor[i],tamanho);
    }
    
}

int LEVazia (TipoLista Lista){
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere_Lista_Encadeada(TipoItem x, TipoLista *Lista){

    struct Celula* novo;
    novo = (struct Celula*) malloc(sizeof(struct Celula));
    novo->Item = x;

    int cont = 0;

    struct Celula* Aux;
    Aux = Lista -> Primeiro -> Prox;
    while (cont == 0){
        if(Aux == NULL){
            Aux = novo;
            Aux -> Prox = NULL;
            Lista -> Primeiro -> Prox = Aux;
            Lista -> Ultimo = Aux;
            cont++;
        }else if(Aux->Prox == NULL){
            Aux->Prox = novo;
            novo -> Prox = NULL;
            Lista -> Ultimo = novo;
            cont++;
        }
        Aux = Aux->Prox;
    }
}
void Insere_Hash_Lista_Encads(int chave, TipoLista *vetor, int tamanho){
    printf("\ncriei as listas");
    int posicaoHash = 0;
    TipoItem item;
    posicaoHash = chave%tamanho;  
    int aux = 0;
    item.num = chave;
    Insere_Lista_Encadeada(item, &vetor[posicaoHash]);
    printf("\nAdicionei o item %d na lista %d",item.num,posicaoHash);

}

void Cria_Listas_Encads(TipoLista *vetor, int tamanho){
    for(int i=0; i<tamanho; i++){
        CLEVazia(&vetor[i]);
    }
}

void Buscar_Lista_Encadeada(TipoLista Lista,int chave,int tamanho){
    Celula* Aux;
    Aux = Lista.Primeiro -> Prox;
    int cont =0,cont2=0;
    while (Aux != NULL){
        if(Aux->Item.num == chave){
            printf ("%d na pos %d, na lista %d",Aux->Item.num,cont,chave%tamanho );
            cont2++;
            Aux = Aux->Prox;
        } 
        else{
            Aux=Aux->Prox;
            cont++;  
        } 

    }if(cont2 == 0){
        printf("\nChave não encontrada !");
    }

}

void Buscar_Hash_Encadeado(TipoLista *vetor,int chave, int tamanho){
    printf("\n");
    int lista = chave%tamanho;
    Buscar_Lista_Encadeada(vetor[lista],chave,tamanho);
}

void Exclusao_Elemento_Lista_Encadeada(TipoLista Lista,int chave,int tamanho){
    Celula* Aux;
    Aux = Lista.Primeiro;
    int cont =0;
    while (Aux->Prox!= NULL){
        if(Aux->Prox->Item.num == chave){
            Celula *Removs;
            Removs = Aux->Prox;
            Aux->Prox = Aux->Prox->Prox;
            free(Removs);
            printf("Removido ! :D");
            cont++;    
        }
        else{
            Aux=Aux->Prox;
        }

    }if(cont == 0) printf("\nNao foi possivel remover !");

}

void Exclusao_Elemento_Hash_Encadeado(TipoLista *vetor,int chave, int tamanho){
    printf("\n");
    int lista = chave%tamanho;
    Exclusao_Elemento_Lista_Encadeada(vetor[lista],chave,tamanho);
}