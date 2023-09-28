#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Graph {
  int numVertices;
  int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void DFS(Graph* graph, int startVertex, int visited[]) {
  visited[startVertex] = 1;
  printf("%d ", startVertex);

  for (int i = 0; i < graph->numVertices; i++) {
    if (graph->adjacencyMatrix[startVertex][i] && !visited[i]) {
      DFS(graph, i, visited);
    }
  }
}

int main(void) {
  Graph graph;
  graph.numVertices = 4;

  // Assume that the graph is an adjacency matrix representation
  // and the graph is as follows:
  // 0 1 2 3
  // ----------
  // 0 1 1 0
  // 1 0 0 1
  // 1 0 0 1
  // 0 1 1 0
  graph.adjacencyMatrix[0][1] = 1;
  graph.adjacencyMatrix[0][2] = 1;
  graph.adjacencyMatrix[1][0] = 1;
  graph.adjacencyMatrix[1][3] = 1;
  graph.adjacencyMatrix[2][0] = 1;
  graph.adjacencyMatrix[2][3] = 1;
  graph.adjacencyMatrix[3][1] = 1;
  graph.adjacencyMatrix[3][2] = 1;

  // Initialize the visited array
  int visited[MAX_VERTICES];
  for (int i = 0; i < graph.numVertices; i++) {
    visited[i] = 0;
  }

  printf("DFS: ");
  DFS(&graph, 0, visited);

  return 0;
}