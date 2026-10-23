#include <stdio.h>
#include <string.h>

#define MAX_VERTICES 6

typedef struct No {
    int vertice;
    int peso;
    struct No *proximo;
} No;

typedef struct {
    int num_vertices;
    No *lista[MAX_VERTICES];
} GrafoLista;


// Adiciona uma aresta nao direcionada
void adicionar_aresta(GrafoLista *g, int u, int v, int peso) {
    No *novo = malloc(sizeof(No));
    novo->vertice = v;
    novo->peso = peso;
    novo->proximo = g->lista[u];
    g->lista[u] = novo;

    novo = malloc(sizeof(No));
    novo->vertice = u;
    novo->peso = peso;
    novo->proximo = g->lista[v];
    g->lista[v] = novo;
}


// Algoritmo de Dijkstra
void dijkstra(GrafoLista *g, int origem) {
    int distancia[MAX_VERTICES];
    int pred[MAX_VERTICES];
    int processado[MAX_VERTICES];

    for (int i = 0; i < g->num_vertices; i++) {
        distancia[i] = -1;
        pred[i] = -1;
        processado[i] = 0;
    }

    distancia[origem] = 0;

    for (int i = 0; i < g->num_vertices; i++) {
        int u = -1;
        int menor = -1;

        for (int j = 0; j < g->num_vertices; j++) {
            if (!processado[j] &&
                distancia[j] != -1 &&
                (menor == -1 || distancia[j] < menor)) {
                menor = distancia[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        processado[u] = 1;

        No *no = g->lista[u];

        while (no != NULL) {
            int v = no->vertice;
            int peso = no->peso;

            if (!processado[v] &&
                (distancia[v] == -1 ||
                 distancia[v] > distancia[u] + peso)) {
                distancia[v] = distancia[u] + peso;
                pred[v] = u;
            }

            no = no->proximo;
        }
    }

    printf("Vertice | Distancia | Predecessor\n");

    for (int i = 0; i < g->num_vertices; i++) {
        printf("   %c    |", 'A' + i);

        if (distancia[i] == -1)
            printf(" Inalcancavel |");
        else
            printf("     %d      |", distancia[i]);

        if (pred[i] == -1)
            printf(" -\n");
        else
            printf("     %c\n", 'A' + pred[i]);
    }
}


int main(void) {
    GrafoLista g;
    g.num_vertices = 6;

    for (int i = 0; i < MAX_VERTICES; i++)
        g.lista[i] = NULL;

    // A = 0, B = 1, C = 2, D = 3, E = 4, F = 5

    adicionar_aresta(&g, 0, 1, 4);  // A -- B
    adicionar_aresta(&g, 1, 3, 5);  // B -- D
    adicionar_aresta(&g, 1, 4, 8);  // B -- E
    adicionar_aresta(&g, 2, 3, 4);  // C -- D
    adicionar_aresta(&g, 2, 4, 10); // C -- E
    adicionar_aresta(&g, 3, 4, 2);  // D -- E
    adicionar_aresta(&g, 3, 5, 1);  // D -- F
    adicionar_aresta(&g, 1, 2, 1);  // B -- C
    adicionar_aresta(&g, 0, 2, 2);  // A -- C
    adicionar_aresta(&g, 4, 5, 3);  // E -- F

    dijkstra(&g, 0); // Origem A

    return 0;
}