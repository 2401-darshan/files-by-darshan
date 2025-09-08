#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// -------- Graph using adjacency matrix --------
int adj[MAX][MAX];
int visited[MAX];
int queue[MAX], front = -1, rear = -1;

// -------- Queue functions for BFS --------
void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}
int isEmpty() {
    return (front == -1 || front > rear);
}

// -------- DFS function --------
void DFS(int v, int n) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            DFS(i, n);
        }
    }
}

// -------- BFS function --------
void BFS(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

// -------- Main --------
int main() {
    int n, e, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (src dest):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &src, &dest);
        adj[src][dest] = 1;
        adj[dest][src] = 1; // undirected graph
    }

    printf("\nDFS starting from vertex 0: ");
    for (int i = 0; i < n; i++) visited[i] = 0;
    DFS(0, n);

    printf("\nBFS starting from vertex 0: ");
    BFS(0, n);

    return 0;
}
