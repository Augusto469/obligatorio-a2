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
    }
    

    int M;
    cin >> M;
    HashCerrado wordList = HashCerrado(M);

    for (int i = 0; i < M; i++)
    {
        string word;
        cin >> word;
        wordList.insert(word);
    }
    
    for (int i = 0; i < M; i++)
    {
        cout << dictionary.exists(i) << endl;
    }
    
    return 0;
}
