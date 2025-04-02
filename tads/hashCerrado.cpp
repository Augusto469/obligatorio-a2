#include <string>
#include <iostream>
using namespace std;

class HashCerrado
{
private:
    string *arr;
    int size;
    int elements;

    int hash(string key)
    {
        int h = 0;
        for (int i = 0; i < key.length(); i++)
        {
            h = 31 * h + int(key[i]);
            return h;
        }
    }

    int hash2(string key)
    {
        int h = 0;
        for (int i = 0; i < key.length(); i++)
        {
            h = 37 * h + int(key[i]);
            return h; // TODO: no olvidarse de documentar
        }
    }

public:
    HashCerrado(int _size)
    {
        arr = new string[_size * 2]();
        size = _size * 2;
        elements = _size;
    }

    void insert(string word)
    {
        int position = abs(this->hash(word)) % this->size;
        int tries = 0;
        bool wasInserted = false;
        while (!wasInserted)
        {
            if (!exists(word))
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
    }

    bool exists(string word)
    {
        int position = abs(this->hash(word)) % this->size;
        int tries = 0;
        while (tries < this->size)
        {
            if (arr[position] == "")
            {
                return false;
            }
            else
            {
                if (arr[position] == word)
                {
                    return true;
                }
                else
                {
                    tries++;
                    position = abs(this->hash(word) + this->hash2(word) * tries) % this->size;
                }
            }
            return false;
        }
    }
};