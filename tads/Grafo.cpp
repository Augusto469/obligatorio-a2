#include <iostream>
using namespace std;

struct Edge {
    int origin;
    int destiny;
    int weight;
    Edge* next;
}

class Graph {
    private:
        int V;
        Edge** adjList;

    public:
        Graph(int _V) {
            V = _V;
            adjList = new Edge*[_V]();
        }

        void insertEdge(int v, int w, int c){
            Edge newEdge = new Edge();

            newEdge->origin = v;
            newEdge->destiny = w;
            newEdge->weight = c;

            newEdge->next = adjList[v];
            adjList[v] = newEdge;
        }

        void dijkstra(Grafo graph, int _origin){
            bool* visited = new bool[V];
            int* cost = new int[V];
            int* cameFrom = new int[V];

            for (int i = 0; i < V; i++)
            {
                visited[i] = false;
                cost[i] = 9999999999;
                cameFrom[i] = -1;
            }
            
            visited[_origin] = true;
            cost[_origin] = 0

            // crear cola de prioridad
            Heap queue = new Heap(); // PROGRAMAR HEAP

            // cargarla con los vecinos del origen
            Edge neighbors = graph.getNeighbors(_origin); // PROGRAMAR GETNEIGHBORS

            










            


            // mientras la cola no esté vacía
            while(!queue.isEmpty()){ // PROGRAMAR ISEMPTY
                // tomar el vértice de menor costo no procesado
                Edge notProcesed = queue.dequeue();

                // y realizar el algoritmo (ajustar los arrays visited, cost y cameFrom)


        }
}