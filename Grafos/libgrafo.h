#include <stdlib.h>
#include <stdio.h>

#if WIN32 || win32
    #include <windows.h>
#elif linux || UNIX
    #include <time.h>
#endif

#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define TRUE 1
#define FALSE 0

/**
* Biblioteca de definição de grafo
* e suas operações.
*/

/**
* Definição da estrutura Grafo.
* n_vert: número de vértices do grafo
* n_arst: inteiro para contagem
* em tempo de execução do número de arestas
* **p_mat: ponteiro para matriz de adjacências em
* indireção múltipla: p_mat é indexado na memória
* por vários *p_mat[i] (0 <= i <= n_vert) e cada um
* deles é um ponteiro de inteiros, que serão
* indexados na memória por p_mat[i][j] (0 <= j <= n_vert),
* originando uma matriz n_vert x n_vert com
* alocação dinâmica de memória.
* @author Lakshamana
*/
typedef struct t_grafo{
    int n_vert;
    int n_arst;
    int **p_mat;
} Grafo;


/* ------ Funções relacionadas a conceitos básicos de grafos ------ */

/**
* Alocação dinâmica do Grafo
* e sua matriz de adjacências,
* preenchendo-a com zeros inicialmente.
* @param nv - número de vétices
* @return Grafo *
*/
Grafo * a_gamat(int nv);

/**
* Liberação (destruição) do grafo da memória,
* sua matriz de adjacências e seus ponteiros.
* @param g - um grafo qualquer
* @return NULL
*/
Grafo * f_gamat(Grafo *g);

/**
* Libera um grafo da memória se
* não estiver vazio, e aloca um
* novo grafo na memória.
* @param g - um grafo qualquer
* @param nv - número de vérices
*/
void n_grafo(Grafo **g, int nv);

/**
* Leitura do novo
* grafo alocado na memória
* @param g - um grafo previamente
* alocado na memória
*
*/
int ler_grafo(Grafo **g);

/**
* Apresentar menu de grafo
* @author Lakshamana
* @return 1 - grafo direcionado.
* @return 2 - grafo não-direcionado.
*/
int menu_n_grafo();

/**
* Mostrar matriz de adjacências
* de um dado grafo
* @author Lakshamana
*/
void g_show(Grafo *g);

/**
* Insere aresta de um
* grafo direcionado
* @author Lakshamana
*/
void ins_dir_amat(Grafo *g, int p, int v1, int v2);

/**
* Insere aresta de um
* grafo não-direcionado
* @author Lakshamana
*/
void ins_ndir_amat(Grafo *g, int p, int v1, int v2);

/**
* Remove aresta de um
* grafo direcionado
* @author Lakshamana
*/
void rmv_dir_amat(Grafo *g, int v1, int v2);

/**
* Remove aresta de um
* grafo não-direcionado
* @author Lakshamana
*/
void rmv_ndir_amat(Grafo *g, int v1, int v2);

/**
* Existe aresta de um dado grafo
* @author Lakshamana
*/
int ex_amat(Grafo *g, int v1, int v2);

/**
* Grau de um vértice
* @author Lakshamana
*/
int grau(Grafo *g, int v);

/**
* Verificar se grafo é regular
* @author Lakshamana
*/
int reg(Grafo *g);


/* ------ Funções relacionadas a caminhamento em grafos ------ */

/**
* Verifica se a lista de
* adjacências está vazia
* @author Ziviani
*/
int ls_vazia_amat(Grafo *g, int vert);

/**
* Primeiro adjacente da lista de adjacências
* de um dado vértice
* @author Ziviani
*/
int primeiro_ls_amat(Grafo *g, int v);

/**
* Próximo adjacente de um dado vértice
* @author Ziviani
*/
void prox_adj_amat(Grafo *g, int *v, int *adj,
    int *peso, int *prox, int *fim_ls);

/**
* Algoritmo de busca em profundidade
* @author Ziviani
*/
void visita_dfs(Grafo *g, int u, int *tmp, int *d,
    int *t, int *cor, int *ant);

/**
* Inicializador e invólucro do
* algoritmo visita_dfs
* @author Ziviani
*/
void busca_dfs(Grafo *g);

/**
* Estrutura de fila para
* uso da busca em largura
* @author Lakshamana
*/

typedef struct t_fila{
    int v;
    struct t_fila *prox;
}Fila;

/**
* Enfileirar
* @author Lakshamana
*/
void enq(Fila **f, int v);

/**
* Desenfileirar, retornando o
* valor do vértice
* @author Lakshamana
*/
void deq(Fila **f, int *v);

/**
* Verifica se a fila está vazia
* @author Lakshamana
*/
int empty_q(Fila *f);

/**
* Retorna primeiro vértice da fila
* @author Lakshamana
*/
void primeiro_f(Fila *f, int *v);


/* ------ Funções de contagem de tempo de execução ------ */

/* As funções de contagem de tempo de execução de
alguma função geralmente seguem a seguinte forma:
* double nome(Tipo arg1, ..., Tipo argN,
              (tipo) (*f)(Tipo arg1, ..., Tipo argN){
              #if linux
                iniciar_contagem_linux();
                f(arg1, ..., argN);
                concluir_contagem_linux();
                retornar tempo_total;
              #elif WIN32
                iniciar_contagem_windows();
                f(arg1, ..., argN);
                concluir_contagem_windows();
                retornar tempo_total;
              #else macosx
                iniciar_contagem_macosx();
                f(arg1, ..., argN);
                concluir_contagem_macosx();
                retornar tempo_total;
              #endif
* }
*/

/**
* Executa a contagem de tempo
* de execução da função da Questão I
* do trabalho de Grafos
* @author Lakshamana
* @param (*f)(Grafo *, int, int) recebe
* @param Grafo *g o grafo para ser usado por f
* @param int v1 um vértice
* @param int v2 outro vértice
* ponteiro para função ex_amat(Grafo *, int, int)
* @return o tempo de execução
*/
double q1_timecount(Grafo *g, int v1, int v2,
                    int (*f)(Grafo *, int, int));

/** Executa a contagem de tempo
* de execução da função da Questão II
* do trabalho de Grafos
* @author Lakshamana
* @param (*f)(Grafo *g, Lista *l, int a)
* @return o tempo de execução
*/
//Expandir a assinatura da função.
double q2_timecount();
