#include <iostream>
#include "tads\Grafo.cpp"
using namespace std;

int main(){
    int V;
    cin >> V;
    
    int E;
    cin >> E;

    Graph graph = Graph(V);
    for (int i = 0; i < E; i++)
    {
        int v;
        cin >> v;

        int w;
        cin >> w;

        int c;
        cin >> c;

        graph.insertEdge(v-1,w-1,c);
    }

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int origin;
        cin >> origin;
        graph.dijkstra(origin-1);
    }

    return 0;
}