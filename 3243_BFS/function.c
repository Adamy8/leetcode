/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int *neighbours;
    int count;
    int capacity;
}node;

void addEdge(node* Graph, int u, int v){
    //queries is in form: [2,4] and u=2, v=4
    if(Graph[u].count == Graph[u].capacity){
        Graph[u].capacity *= 2;
        Graph[u].neighbours = realloc(Graph[u].neighbours, Graph[u].capacity * sizeof(int));
    }
    Graph[u].neighbours[ Graph[u].count++ ] = v;
}

void initializeGraph(node* Graph, int n){
    for(int i=0; i < n ;i++){
        Graph[i].neighbours = (int*)malloc(2 * sizeof(int));
        Graph[i].capacity = 2;
        (Graph[i].neighbours)[0] = i+1;
        (Graph[i].neighbours)[1] = -1;
        Graph[i].count = 1;
        if(i == n-1){
            (Graph[i].neighbours)[0] = -1;
            Graph[i].count = 0;
        }
    }
}

void setAllToFalse(bool* visited, int n){
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
}


int BFS(node* graph, bool* visited, int n){
    setAllToFalse(visited, n);
    int* dist = (int*)calloc(n, sizeof(int));   // distance from node 0
    dist[0] = 0;
    visited[0] = true; // 1 for true, 0 for false

    int* queue = (int*)malloc(n * sizeof(int)); //
    int front = 0, rear = 0;
    queue[rear++] = 0;
    dist[0] = 0;

    while(front < rear){
        int current = queue[front++];
        if(current == n-1) break; // means we get to the end
        // explore neighbours:

        printf("%d has neighbour: ",current); //debug
        for(int i=0; i<graph[current].count;i++){
            int curNeighbour = graph[current].neighbours[i];
            printf("%d ",curNeighbour); //debug
            if(!visited[curNeighbour]){
                dist[curNeighbour] = dist[current] + 1;
                visited[curNeighbour] = true;
                queue[rear++] = curNeighbour;
            }
        }
        printf("\n"); //debug
    }

    printf("dist: "); //debug
    for(int i=0;i<n;i++) printf("%d ",dist[i]); //debug
    printf("\n"); //debug

    int result = dist[n-1];
    free(queue);
    free(dist);
    return result;
}

int* shortestDistanceAfterQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    bool* visited = (bool*)malloc(n * sizeof(bool));
    // setAllToFalse(visited, n);

    node* Graph = (node*)malloc(sizeof(node) * n);
    initializeGraph(Graph,n);
    
    int* result = (int*)malloc(queriesSize * sizeof(int));
    for (int i = 0; i < queriesSize; i++) {
        addEdge(Graph, queries[i][0], queries[i][1]);
        result[i] = BFS(Graph, visited, n);
    }
    

    free(visited);
    for(int i=0;i<n;i++) free(Graph[i].neighbours);
    *returnSize = queriesSize;
    return result;
}


//for test only
int main() {
    int n = 5;
    int queriesSize = 3;
    int* queries[] = {
        (int[]){2, 4},
        (int[]){0, 2},
        (int[]){0, 4}
    };

    int returnSize;
    int* result = shortestDistanceAfterQueries(n, queries, queriesSize,0, &returnSize);

    printf("Shortest distances:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}