#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Graph {
  int numVertices;
  int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

typedef struct Queue {
  int items[MAX_VERTICES];
  int front, rear;
} Queue;

void enqueue(Queue* queue, int item) {
  queue->items[queue->rear] = item;
  queue->rear = (queue->rear + 1) % MAX_VERTICES;
}

int dequeue(Queue* queue) {
  int item = queue->items[queue->front];
  queue->front = (queue->front + 1) % MAX_VERTICES;
  return item;
}

int isEmpty(Queue* queue) {
  return queue->front == queue->rear;
}

void BFS(Graph* graph, int startVertex, int visited[]) {
  Queue queue;
  queue.front = queue.rear = 0;

  enqueue(&queue, startVertex);
  visited[startVertex] = 1;

  while (!isEmpty(&queue)) {
    int currentVertex = dequeue(&queue);
    printf("%d ", currentVertex);

    for (int i = 0; i < graph->numVertices; i++) {
      if (graph->adjacencyMatrix[currentVertex][i] && !visited[i]) {
        enqueue(&queue, i);
        visited[i] = 1;
      }
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

  printf("BFS: ");
  BFS(&graph, 0, visited);

  return 0;
}