#include <string>
#include <iostream>
using namespace std;

struct Node {
    string key;
    Node* next;

    Node(string _key){
        key = _key;
        next = nullptr;
    }
};

class HashAbierto {
    private:
        Node** arr;
        int size;

        int hash(string key){
            int h = 0;
            for (int i = 0; i < key.length(); i++){
                h = 31 * h + int(key[i]);
            return h;
            }
        }

    public:
        HashAbierto(int _size){
            arr = new Node*[_size]();
            size = _size;
        }

        void insert(string email) {
            int position = hash(email) % size;
            if(!exists(email)) {
                Node* toInsert = new Node(email);
                if(arr[position] == nullptr){
                    arr[position] = toInsert;
                }
                else{
                    toInsert->next = arr[position];
                    arr[position] = toInsert;
                }
            }
        }

        bool exists(string email) {
            int position = hash(email) % size;  
            Node* aux = arr[position];

            while(aux != nullptr){
                if(aux->key == email){
                    return true;
                }
                aux = aux->next;
            }
            return false;
        }

        int countNodes(){
            int nodes = 0;
            for(int i = 0; i < this->size; i++){
                Node* aux = arr[i];
                while(aux != nullptr){
                    nodes++;
                    aux = aux->next;
                }
            }
            return nodes;
        }
};
