#pragma once
#include <iostream>
#include "LinkedList.h"

class Hashing
{
private:
    LinkedList<int> *array;
    const int slots;

    int hashFunction(int val)
    {
        return val % slots;
    }

public:
    Hashing(int arraySlots) : slots(arraySlots)
    {
        array = new LinkedList<int>[slots];
    }

    void insert(int key)
    {
        array[hashFunction(key)].AddNodeAtTail(key);
    }

    bool search(int key)
    {
        return array[hashFunction(key)].SearchNode(key);
    }

    void display()
    {
        for (int i = 0; i < slots; i++)
        {
            cout << i << ":";
            array[i].DisplayList();
            cout << endl;
        }
    }
};
