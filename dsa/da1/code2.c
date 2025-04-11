#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 4  // Number of vertices

// Structure to represent an edge
typedef struct {
    int src, dest, weight;
} Edge;

// Structure to represent a graph
typedef struct {
    int numEdges;
    Edge edges[5];
} Graph;

// Structure to represent a subset for union-find
typedef struct {
    int parent, rank;
} Subset;

// Find set of an element i (uses path compression)
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union of two sets (by rank)
void unionSets(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);
    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Comparator for sorting edges by weight
int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Kruskal's Algorithm for MST
void kruskalMST(Graph* graph) {
    Edge result[V];
    int e = 0;
    int i = 0;
    
    qsort(graph->edges, graph->numEdges, sizeof(Edge), compareEdges);
    
    Subset subsets[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    
    while (e < V - 1 && i < graph->numEdges) {
        Edge nextEdge = graph->edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }
    
    printf("MST:");
    for (i = 0; i < e; i++)
        printf(" (%d - %d: %d)", result[i].src, result[i].dest, result[i].weight);
    printf("\n");
}

// Dijkstra's Algorithm for Shortest Path Tree
void dijkstraSPT(int graph[V][V], int src) {
    int dist[V];
    int visited[V] = {0};
    
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    
    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u;
        for (int v = 0; v < V; v++)
            if (!visited[v] && dist[v] <= min)
                min = dist[v], u = v;
        
        visited[u] = 1;
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    
    printf("SPT from %d:", src);
    for (int i = 0; i < V; i++)
        printf(" (%d: %d)", i, dist[i]);
    printf("\n");
}

int main() {
    Graph graph = {5, {{0, 1, 1}, {0, 2, 4}, {1, 2, 2}, {1, 3, 3}, {2, 3, 5}}};
    kruskalMST(&graph);
    
    int adjMatrix[V][V] = {
        {0, 1, 4, 0},
        {1, 0, 2, 3},
        {4, 2, 0, 5},
        {0, 3, 5, 0}
    };
    dijkstraSPT(adjMatrix, 0);
    
    return 0;
}
