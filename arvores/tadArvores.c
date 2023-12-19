#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadArvores.h"

/*********************** CAMINHAMENTOS ABP ***********************/

void preFichaveadoEsq(NodoABP *a){
    if (a!= NULL){
        printf("%d\n",a->chave);
        preFichaveadoEsq(a->esq);
        preFichaveadoEsq(a->dir);
    }
}

void preFichaveadoDir(NodoABP *a){
    if (a!= NULL){
        printf("%d\n",a->chave);
        preFichaveadoDir(a->dir);
        preFichaveadoDir(a->esq);
    }
}

void centralEsq(NodoABP *a){
    if (a!= NULL){
        centralEsq(a->esq);
        printf("%d\n",a->chave);
        centralEsq(a->dir);
    }
}

void centralDir(NodoABP *a){
    if (a!= NULL){
        centralDir(a->dir);
        printf("%d\n",a->chave);
        centralDir(a->esq);
    }
}

void posFichaveadoEsq(NodoABP *a){
    if (a!= NULL){
        posFichaveadoEsq(a->esq);
        posFichaveadoEsq(a->dir);
        printf("%d\n",a->chave);
    }
}

void posFichaveadoDir(NodoABP *a){
    if (a!= NULL){
        posFichaveadoDir(a->dir);
        posFichaveadoDir(a->esq);
        printf("%d\n",a->chave);
    }
}

void ImprimePreFichaveadoEsq(NodoABP *a, int nivel){ // considera os níveis
    if (a!= NULL){
        for(int i=0; i<nivel;i++){
            printf("=");
        }
        printf("%d\n",a->chave);
        Imprime(a->esq, nivel+1);
        Imprime(a->dir, nivel+1);
    }
}

/*********************** ABP OPERAÇÕES ***********************/

NodoABP* cria(){
    return NULL;
}

NodoABP* consulta(NodoABP *a, Chave chave) { // retorna nulo se não encontra a chave de consulta
    if (a==NULL)
        return NULL;
    else if (a->chave == chave)
        return a;
    else
        if (a->chave > chave)
            return consulta(a->esq,chave);
        else
            return consulta(a->dir,chave);
} 

NodoABP* insere(NodoABP *a, Chave chave){
    if (a == NULL){ // raiz é nula
        a = (NodoABP*) malloc(sizeof(NodoABP));
        a->chave = chave;
        a->esq = NULL;
        a->dir = NULL;
    } else{ 
        if (chave < a->chave) // chave é menor que a raiz, insere a esquerda
            a->esq = insere(a->esq,chave);
        else // chave é maior que a raiz, insere a direira
            a->dir = insere(a->dir,chave);
    }
    
    return a;
}

NodoABP* maior( NodoABP* a){ // auxiliar da remove
    if(a != NULL)
        while(a->dir != NULL)
            a = a->dir;

    return a;
}

NodoABP* remove(Chave chave, NodoABP* a){
    NodoABP* TmpCell;

    if(a == NULL)
        printf("Chave nao encontrada!\n");
    else if(chave < a->chave) // vai para a subarvore esquerda
        a->esq = remove(chave, a->esq);
    else if(chave > a->chave) // vai para a subarvore direita 
        a->dir = remove(chave, a->dir);
    else  // achou o elemento a ser removido */
        if(a->esq && a->dir)  // o elemento tem as 2 subarvores 
        {
            // substitui pelo maior valor da sub�rvore esquerda
            TmpCell = maior(a->esq);
            a->chave = TmpCell->chave;
            a->esq = remove(a->chave, a->esq);
        }
        else // uma ou nenhuma sub-arvore 
        {
            TmpCell = a;
            if(a->esq == NULL) // substitui pelo filho dir, se nao tiver filhos substitui por NULL
                a = a->dir;
            else if(a->dir == NULL)
                a = a->esq; //substitui pelo filho esq
            free(TmpCell);
        }

    return a;
}

int contaNodo(NodoABP  *a){
    if (a == NULL)
        return 0;
    else
        return 1 + contaNodo(a->dir) + contaNodo(a->esq);

}

int altura(NodoABP *a){
    int altEsq, altDir;
    if (a == NULL)
        return 0;
    else{
        altEsq = altura(a->esq);
        altDir = altura(a->dir);
        if (altEsq > altDir)
            return (1 + altEsq);
        else
            return (1 + altDir);
    }
}

int calculaFatorNodo(NodoABP *a){
    if(a==NULL){
        return 0;
    } else{
        return abs(altura(a->esq) - altura(a->dir));
    }

}

void calculaFatorArvoreAux(NodoABP *a, int *fatorArvore){
    if(a==NULL){
        return;
    }else {
        int fator = calculaFatorNodo(a);
        if(fator>*fatorArvore){
            *fatorArvore = fator;
        }
        calculaFatorArvoreAuchave(a->dir, fatorArvore);
        calculaFatorArvoreAuchave(a->esq, fatorArvore);
        return;
    }

}

int calculaFatorArvore(NodoABP *a){
    int fatorArvore=0;
    calculaFatorArvoreAuchave(a, &fatorArvore);
    return fatorArvore;
}

/*********************** CAMINHAMENTOS AVL ***********************/

void preFichaveadoEsqAVL(NodoAVL *a){
    if (a!= NULL){
        printf("%d\n",a->chave);
        preFichaveadoEsq(a->esq);
        preFichaveadoEsq(a->dir);
    }
}

void preFichaveadoDirAVL(NodoAVL *a){
    if (a!= NULL){
        printf("%d\n",a->chave);
        preFichaveadoDir(a->dir);
        preFichaveadoDir(a->esq);
    }
}

void centralEsqAVL(NodoAVL *a){
    if (a!= NULL){
        centralEsq(a->esq);
        printf("%d\n",a->chave);
        centralEsq(a->dir);
    }
}

void centralDirAVL(NodoAVL *a){
    if (a!= NULL){
        centralDir(a->dir);
        printf("%d\n",a->chave);
        centralDir(a->esq);
    }
}

void posFichaveadoEsqAVL(NodoAVL *a){
    if (a!= NULL){
        posFichaveadoEsq(a->esq);
        posFichaveadoEsq(a->dir);
        printf("%d\n",a->chave);
    }
}

void posFichaveadoDirAVL(NodoAVL *a){
    if (a!= NULL){
        posFichaveadoDir(a->dir);
        posFichaveadoDir(a->esq);
        printf("%d\n",a->chave);
    }
}

void ImprimePreFichaveadoEsqAVL(NodoAVL *a, int nivel){ // considera os níveis
    if (a!= NULL){
        for(int i=0; i<nivel;i++){
            printf("=");
        }
        printf("%d\n",a->chave);
        Imprime(a->esq, nivel+1);
        Imprime(a->dir, nivel+1);
    }
}


/*********************** ROTAÇÕES ***********************/

NodoAVL* simplesDireita(NodoAVL* p){
    NodoAVL *u;

    u = p->esq;
    p->esq = u->dir;
    u->dir = p;
    p->fator = 0;
    p = u;

    return p;
}

NodoAVL* simplesEsquerda(NodoAVL *p){
    NodoAVL *z;

    z = p->dir;
    p->dir = z->esq;
    z->esq = p;
    p->fator = 0;
    p = z;

    return p;
} 

NodoAVL* duplaDireita(NodoAVL* p){
    NodoAVL *u, *v;

    u = p->esq;
    v = u->dir;
    u->dir = v->esq;
    v->esq = u;
    p->esq = v->dir;
    v->dir = p;

    if (v->fator == 1) 
        p->fator = -1;
    else 
        p->fator = 0;
    if (v->fator == -1) 

        u->fator = 1;
    else 
        u->fator = 0;
    p = v;

    return p;
}

NodoAVL* duplaEsquerda(NodoAVL *p){
    NodoAVL *z, *y;

    z = p->dir;
    y = z->esq;
    z->esq = y->dir;
    y->dir = z;
    p->dir = y->esq;
    y->esq = p;

    if (y->fator == -1)
        p->fator = 1;
    else 
        p->fator = 0;
    if (y->fator == 1) 
        z->fator = -1;
    else 
        z->fator = 0;
    
    p = y;
    return p;
}

/*********************** AVL OPERAÇÕES ***********************/

NodoAVL* criaAVL(){
    return NULL;
}

NodoAVL* consultaAVL(NodoAVL *a, Chave chave) { // retorna nulo se não encontra a chave de consulta
    if (a==NULL)
        return NULL;
    else if (a->chave == chave)
        return a;
    else
        if (a->chave > chave)
            return consultaAVL(a->esq,chave);
        else
            return consultaAVL(a->dir,chave);
} 

NodoAVL* Caso1 (NodoAVL *a , int *ok){
    NodoAVL *z;
    z = a->esq;
    if (z->fator == 1)
    a = simplesDireita(a);

    else
    a = duplaDireita(a);

    a->fator = 0;
    *ok = 0;
    return a;
}

NodoAVL* Caso2 (NodoAVL *a , int *ok){
    NodoAVL *z;
    z = a->dir;
    if (z->fator == -1)
    a = simplesEsquerda(a);

    else
    a = duplaEsquerda(a);

    a->fator = 0;
    *ok = 0;
    return a;
}

NodoAVL* InsereAVL(NodoAVL *a, Chave chave, int *ok){
    if (a == NULL) {
        a = (NodoAVL*) malloc(sizeof(NodoAVL));
        a->chave = chave;
        a->esq = NULL;
        a->dir = NULL;
        a->fator = 0;
        *ok = 1;
    }
    else if (chave < a->chave) {
        a->esq = InsereAVL(a->esq,chave,ok);
        if (*ok) {
            switch (a->fator) {
                case -1: a->fator = 0; *ok = 0; break;
                case 0: a->fator = 1; break;
                case 1: a=Caso1(a,ok); break;
            }
        }
    }
    else {
        a->dir = InsereAVL(a->dir,chave,ok);
        if (*ok) {
            switch (a->fator) {
                case 1: a->fator = 0; *ok = 0; break;
                case 0: a->fator = -1; break;
                case -1: a = Caso2(a,ok); break;
            }
        }
    }
 return a;
}
