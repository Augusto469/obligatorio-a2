#include <iostream>
#include "tads\Grafo.cpp"
using namespace std;

int main(){
    int V;
    cin << V;
    
    int E;
    cin << E;

    Grafo graph = new Grafo(V);

    for (int i = 0; i < E; i++)
    {
        int v;
        cin << v;

        int w;
        cin << w;

        int c;
        cin << c;

        graph.insertEdge(v,w,c);
    }
    
    int N;
    cin << N;

    for (int i = 0; i < N; i++)
    {
        int origin;
        cin << origin;

        dijkstra(graph,origin);
    }
    
    return 0;
}