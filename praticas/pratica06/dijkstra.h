
#ifndef GRAFO_H
#define GRAFO_H

#define MAX_VERTICES 6

// No da lista de adjacencia
typedef struct No {
    int vertice;
    int peso;
    struct No *proximo;
} No;

// graf da lista de adjacencia
typedef struct {
    int num_vertices;
    No *lista[MAX_VERTICES];
} GrafoLista;

// Prototipos das funcoes
void adicionar_aresta(GrafoLista *g, int u, int v, int peso);

void dijkstra(GrafoLista *g, int origem);

#endif