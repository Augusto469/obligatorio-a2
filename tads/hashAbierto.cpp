#include <string>
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
        HashAbierto(int size){
            arr = new Node*[size]();
        }

        void insert(string email) {
            int position = hash(email);    

            if(!exists(email)) {
                Node* toInsert = new Node(email);
                toInsert->next = arr[position];
                arr[position]->next = toInsert;
            }
        }

        bool exists(string email) {
            int position = hash(email);  
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
            for(int i = 0; i < size; i++){
                Node* aux = arr[i];
                while(aux != nullptr){
                    nodes++;
                    aux = aux->next;
                }
            }
            return nodes;
        }
};
