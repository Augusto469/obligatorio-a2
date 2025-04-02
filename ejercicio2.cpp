#include <cassert>
#include <iostream>
#include <limits>
#include "tads\hashCerrado.cpp"

using namespace std;

int main()
{
    int N;
    cin >> N;
    HashCerrado dictionary = HashCerrado(N);

    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        dictionary.insert(word);
        cout << dictionary.exists(word) << endl;
    }    

    int M;
    cin >> M;
    
  /*  for (int i = 0; i < M; i++)
    {
        string word;
        cin >> word;
        cout << dictionary.exists(word) << endl;
    } */
    
    return 0;
}
