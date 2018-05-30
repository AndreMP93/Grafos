#include<stdio.h>
#include "ListaSimples.h"
#include <stdlib.h>

//Lista de Adjacencia para grafo direcionado

typedef struct TipoGrafo {
  int NumVertices;
  //int NumArestas;
  lista *list[100];
} TipoGrafo;


//A função faz um grafo vazio a aprtir de um grafo passado como parametro
void fGVazio(TipoGrafo *g){
	int i;
	for(i = 0; i < g->NumVertices; i++){
		g->list[i] = (node*)malloc(sizeof(node));
		flvazia(g->list[i]);
	}
}


// A função verifica se um aresta existe
//Se existir a função retorna a posição em que vertive v2
//se encontra na lista de adjacencia de v1
//caso contrario a função retor 0
int verificarAresta(int v1, int v2, TipoGrafo *g){
	int posicao = buscar(v2, g->list[v1]);
	if(posicao != -1){
		return posicao;
	}else{
		return 0;
	}
}

//A função vai acessar o peso de uma aresta
int acessarAresta(int v1, int v2, TipoGrafo *g){
	int aux = verificarAresta(v1,v2,g);
	if(aux != 0){
		return acessaPeso(aux,g->list[v1]);
	}else{
		printf("A aresta nao existe\n");
	}
}

//A funcao retorna o grau de um vertice(v1) pertencente ao
//grafo(g) orientado


int grauVertOrientado(int v1, TipoGrafo *g){
	int entrada=0,saida = g->list[v1]->tamanho;
	int i;
	for(i=0;i<g->NumVertices;i++){
		int aux = buscar(v1, g->list[i]);
			if(aux != -1){
				entrada++;
			}
	}
	return entrada+saida;
}



//A funcao retorna o grau de um vertice(v1) pertencente ao
//grafo(g) nao orientado
 int grauVertice(int v1, TipoGrafo *g){
 	return g->list[v1]->tamanho;
 }
 


//Imprime a lista de adjacencia de cada vertice
void imprimirLAdj(TipoGrafo *g){
	int i;
	for(i = 0; i<g->NumVertices; i++){
		if(g->list[i]->tamanho > 0){
			printf("Vizhos de %d: ",i);
			imprimir(g->list[i]);			
		}
		printf("\n");
	}	
}

//Funçoes de adicionar e remover aresta para grafo orientado

// A função adiciona uma aresta ao grafo
// Recebe como parametro dois inteiros(v1 e v2) representando os vertives
//outro inteiro(peso) representando o peso da aresta
//e um TipoGrafo que repesenta o grafo
void addArestaOrientada(int v1, int v2, int peso, TipoGrafo *g){
	if(v1<g->NumVertices || v2 < g->NumVertices){
		insere(v2,peso, g->list[v1]);
	}else{
		printf("Vertice invalido\n");
	}
}

//A função remove a aresta que liga dois vertices
// Recebe como parametro dois inteiros(v1 e v2) representando os vertives
//e um TipoGrafo que repesenta o grafo
void removerArestaOrientada(int v1, int v2, TipoGrafo *g){
	int posicao = buscar(v2, g->list[v1]);
	if(posicao != -1){
		retira(posicao, g->list[v1]);
		printf("A aresta foi removia\n");
	}else{
		printf("A aresta nao existe\n");
	}
}


//A funçao rebece um grafo(g) como parametro e rotorna o seu transpoosto 
TipoGrafo* transposto(TipoGrafo *g){
	TipoGrafo *gAux = (TipoGrafo*)malloc(sizeof(TipoGrafo));
	gAux->NumVertices = g->NumVertices;
	fGVazio(gAux);
	int i,j;
	for(i=0;i<g->NumVertices;i++){
		for(j=0;j<g->list[i]->tamanho;j++){
			int vertAux= acessar(j+1, g->list[i]);
			int auxPeso = acessarAresta(i,vertAux , g);
			addArestaOrientada(vertAux,i,auxPeso,gAux);
		}
	}
	return gAux;
}

//funçoes de adicionar e remover aresta para grafo não orientado

// A função adiciona uma aresta ao grafo
// Recebe como parametro dois inteiros(v1 e v2) representando os vertives
//outro inteiro(peso) representando o peso da aresta
//e um TipoGrafo que repesenta o grafo
void addAresta(int v1, int v2, int peso, TipoGrafo *g){
	if(v1 < g->NumVertices || v2 < g->NumVertices){
		insere(v2,peso, g->list[v1]);
		insere(v1,peso, g->list[v2]);
	}else{
		printf("Vertice Invalido\n");
	}
}

//A função remove a aresta que liga dois vertices
// Recebe como parametro dois inteiros(v1 e v2) representando os vertives
//e um TipoGrafo que repesenta o grafo
void removerAresta(int v1, int v2, TipoGrafo *g){
	int posicao1 = buscar(v2, g->list[v1]), posicao2 =  buscar(v1, g->list[v2]);
	if(posicao1 != -1){
		retira(posicao1, g->list[v1]);
		retira(posicao2, g->list[v2]);
		printf("A aresta foi removia\n");
	}else{
		printf("A aresta nao existe\n");
	}
}