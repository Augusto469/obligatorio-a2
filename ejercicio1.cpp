#include <cassert>
#include <iostream>
#include <limits>
#include "tads\hashAbierto.cpp"

using namespace std;

int main()
{
    int N;
    cin >> N;

    HashAbierto emails = HashAbierto(N);

    for(int i = 0; i < N; i++){
        string email;
        cin >> email;
        emails.insert(email);
    }

    cout << emails.countNodes() << endl;

    return 0;
}
