#include <iostream>
#include <climits>
#include "heap.cpp"
using namespace std;

class Graph
{
    private:
        int V;
        Edge **adjList;

        Edge *getNeighbors(int vertex)
        {
            return adjList[vertex];
        }

    public:
        Graph(int _V)
        {
            V = _V;
            adjList = new Edge *[_V]();
        }

        void insertEdge(int v, int w, int c)
        {
            Edge* newEdge = new Edge();

            newEdge->origin = v;
            newEdge->destiny = w;
            newEdge->weight = c;

            newEdge->next = adjList[v];
            adjList[v] = newEdge;
        }

        void dijkstra(int _origin)
        {
           // bool *visited = new bool[V];
            int *cost = new int[V];

            for (int i = 0; i < V; i++)
            {
               // visited[i] = false;
                cost[i] = INT_MAX;
            }

            cost[_origin] = 0;

            Heap queue = Heap(V*V);

            Edge start;
            start.origin = _origin;
            start.destiny = _origin;
            start.weight = 0;

            queue.insert(start);
            

            while (!queue.isEmpty())
            {
                Edge notProcesed = queue.removeMin();

                if (notProcesed.weight > cost[notProcesed.destiny]) continue;
                //visited[notProcesed.destiny] = true;

                Edge *neighbors = getNeighbors(notProcesed.destiny);
                while (neighbors != nullptr)
                {

                    if(/*!visited[neighbors->destiny] && */ cost[notProcesed.destiny] + neighbors->weight < cost[neighbors->destiny]){
                        cost[neighbors->destiny] = cost[notProcesed.destiny] + neighbors->weight;
                        Edge neighbor;
                        neighbor.origin = notProcesed.destiny;
                        neighbor.destiny = neighbors->destiny;
                        neighbor.weight = cost[neighbors->destiny];
                        queue.insert(neighbor);
                    }
                    neighbors = neighbors->next;
                }
            }

            // Imprimo datos

            for (int i = 0; i < V; i++)
            {
                if (i == _origin || cost[i] == INT_MAX) {
                    cout << -1 << endl;
                } else {
                    cout << cost[i] << endl;
                }
            }
        }
};