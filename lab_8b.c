/*Implement Bellman-Ford Algorithm for finding the shortest path.
Name- Sanya Agarwal 
Roll no. - R2142230839
Sap id. - 500120145
Date - 11-11-24
*/

#include <stdio.h>
#include <limits.h>
#define V 7  
#define E 10  
 
struct Edge {
    int src, dest, weight;
};
 
void printSolution(int dist[], int prev[], int src) {
    printf("\nNode\tShortest Distance\tPrevious Node\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            printf("%c\t\tINF\t\t\t-\n", i + '1');
        } else {
            printf("%c\t\t%d\t\t\t%c\n", i + '1', dist[i], prev[i] != -1 ? prev[i] + '1' : '-');
        }
    }
}
 
void bellmanFord(struct Edge edges[], int src, int dest) {
    int dist[V];
    int prev[V];
 
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }
    dist[src] = 0;
 
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
            }
        }
    }
 
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains a negative-weight cycle\n");
            return;
        }
    }
 
    printf("Shortest distance from %c to %c is %d\n", src + '1', dest + '1', dist[dest]);
    printSolution(dist, prev, src);
}
 
int main() {
    struct Edge edges[E] = {
        {0, 1, 6}, {0, 2, 5}, {0, 3, 5},
        {1, 4, -1}, {2, 1, -2}, {2, 4, 1},
        {3, 5, -1}, {3, 2, -2},
        {4, 6, 3}, {5, 6, 3}
    };
 
    int src, dest;
    printf("Enter the source (0 for 1, 1 for 2, ..., 6 for 7): ");
    scanf("%d", &src);
    printf("Enter the destination (0 for 1, 1 for 2, ..., 6 for 7): ");
    scanf("%d", &dest);
 
    bellmanFord(edges, src, dest);
 
    return 0;
}
