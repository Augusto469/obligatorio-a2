#include <iostream>
using namespace std;

struct Edge
{
    int origin;
    int destiny;
    int weight;
    Edge *next;
};

class Heap {
    private:
        Edge* heapArr;
        int capacity;
        int size;

        void swim(int pos){
            while(pos > 1 && heapArr[pos/2].weight > heapArr[pos].weight){
                swap(pos, pos/2);
                pos = pos/2;
            }
        }
        void sink(int pos){
            while(pos*2 <= size){
                int smallestChild = pos*2;
                if(smallestChild < size && heapArr[smallestChild].weight > heapArr[smallestChild + 1].weight){
                    smallestChild = pos*2 + 1;
                }

                if(heapArr[pos].weight < heapArr[smallestChild].weight){
                    break;
                }

                swap(pos, smallestChild);
                pos = smallestChild;
            }
        }

        void swap(int pos1, int pos2) {
            Edge aux = heapArr[pos1];
            heapArr[pos1] = heapArr[pos2];
            heapArr[pos2] = aux;
        }

    public:
        Heap(int _capacity){
            heapArr = new Edge[_capacity + 1];
            capacity = _capacity;
            size = 0;
        }

        // ~Heap(){}
        
        void insert(Edge edge){
            if(size != capacity){
                size++;
                heapArr[size] = edge;
                swim(size);
            }
        }

        Edge removeMin(){
            Edge minValue = heapArr[1];

            if(size > 1){
                
                swap(1,size);
                size--;
                sink(1);
            }
            else if (size == 1){
                size--;
            }

            return minValue;
        }

        bool isEmpty(){
            return size == 0;
        }
};