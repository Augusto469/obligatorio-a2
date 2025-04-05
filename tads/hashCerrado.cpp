#include <string>
#include <iostream>
using namespace std;

class HashCerrado
{
private:
    string *arr;
    int size;

    int hash(string key) // o(1) porque son hasta 20 caracteres
    {
        int h = 0;
        for (int i = 0; i < key.length(); i++)
        {
            h = 31 * h + int(key[i]);
        }
        return h; // el return estaba dentro del for y va afuera (me fijé en la ppt del curso)
    }

    int hash2(string key) // o(1) porque son hasta 20 caracteres
    {
        int h = 0;
        for (int i = 0; i < key.length(); i++)
        {
            h = 37 * h + int(key[i]);
        }
        return h; // TODO: no olvidarse de documentar. El return estaba dentro del for y va afuera
    }

public:
    HashCerrado(int _size)
    {
        size = _size * 2;
        arr = new string[size]();
    }

    void insert(string word)
    {
        int position = abs(this->hash(word)) % this->size;
        int tries = 0;
        bool wasInserted = false;
        while (!wasInserted)
        {
            if (arr[position] == "")
            {
                arr[position] = word;
                wasInserted = true;
            }
            else
            {
                tries++;
                position = abs(this->hash(word) + this->hash2(word) * tries) % this->size;
            }
        }
    }

    int exists(string word)
    {
        int position = abs(this->hash(word)) % this->size;
        int tries = 0;
        while (tries < size)
        {
            if (arr[position] == "")
            {
                return 0;
            }
            else
            {
                if (arr[position] == word)
                {
                    return 1;
                }
                else
                {
                    tries++;
                    position = abs(this->hash(word) + this->hash2(word) * tries) % this->size;
                }
            }
        }
    }
};