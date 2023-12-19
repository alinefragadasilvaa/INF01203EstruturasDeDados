typedef int Chave;

/*********************** ABP ESTRUTURA ***********************/

typedef struct NodoABP{
    Chave chave;
    struct NodoABP *esq;
    struct NodoABP *dir;
}NodoABP;

/*********************** AVL ESTRUTURA ***********************/

typedef struct NodoAVL{
    Chave chave;
    int fator;
    struct NodoAVL *esq;
    struct NodoAVL *dir;
} NodoAVL;

/*********************** CAMINHAMENTOS ABP ***********************/

void preFixadoEsqABP(NodoABP *a);
void preFixadoDirABP(NodoABP *a);
void centralEsqABP(NodoABP *a);
void centralDirABP(NodoABP *a);
void posFixadoEsqABP(NodoABP *a);
void posFixadoDirABP(NodoABP *a);
void ImprimePreFixadoEsqABP(NodoABP *a, int nivel);

/*********************** ABP OPERAÇÕES ***********************/

NodoABP* criaABP();
NodoABP* consultaABP(NodoABP *a, Chave chave);
NodoABP* insereABP(NodoABP  *a, Chave chave);
NodoABP* maiorABP( NodoABP* a);
NodoABP* removeABP(Chave chave, NodoABP* a);
int contaNodoABP(NodoABP *a);
int alturaABP(NodoABP *a);
int calculaFatorNodoABP(NodoABP *a);
void calculaFatorArvoreAuxABP(NodoABP *a, int *fatorArvore);
int calculaFatorArvoreABP(NodoABP *a);

/*********************** CAMINHAMENTOS AVL ***********************/

void preFixadoEsqAVL(NodoAVL *a);
void preFixadoDirAVL(NodoAVL *a);
void centralEsqAVL(NodoAVL *a);
void centralDirAVL(NodoAVL *a);
void posFixadoEsqAVL(NodoAVL *a);
void posFixadoDirAVL(NodoAVL *a);
void ImprimePreFixadoEsqAVL(NodoAVL *a, int nivel);
int contaNodoAVL(NodoAVL *a);
int alturaAVL(NodoAVL *a);
int calculaFatorNodoAVL(NodoAVL *a);
void calculaFatorArvoreAuxAVL(NodoAVL *a, int *fatorArvore);
int calculaFatorArvoreAVL(NodoAVL *a);


/*********************** ROTAÇÕES ***********************/

NodoAVL* simplesDireita(NodoAVL* p);
NodoAVL* simplesEsquerda(NodoAVL *p);
NodoAVL* duplaDireita(NodoAVL* p);
NodoAVL* duplaEsquerda(NodoAVL *p);

/*********************** AVL OPERAÇÕES ***********************/

NodoAVL* criaAVL();
NodoAVL* consultaAVL(NodoAVL *a, Chave chave);
NodoAVL* Caso1 (NodoAVL *a , int *ok);
NodoAVL* Caso2 (NodoAVL *a , int *ok);
NodoAVL* InsereAVL(NodoAVL *a, Chave chave, int *ok);
