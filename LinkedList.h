#pragma once

#include <iostream>
using namespace std;

template <class T>
class LinkedList
{
public:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *headptr;

public:
    LinkedList()
    {
        headptr = NULL;
    }

    void AddNodeAtHead(T value)
    {
        Node *temp = new Node;
        temp->data = value;
        temp->next = headptr;
        headptr = temp;
    }

    void AddNodeAtTail(T value)
    {
        Node *temp = new Node;
        Node *counter = headptr;
        temp->data = value;
        temp->next = NULL;
        if (headptr == NULL)
        {
            headptr = temp;
            return;
        }
        while (counter->next != NULL)
        {
            counter = counter->next;
        }
        counter->next = temp;
        
        return;
    }

    void DisplayList()
    {
        Node *temp = headptr;
        while (temp != NULL)
        {
            cout << "|" << temp->data << "|-->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
        return;
    }

    void DisplaySpecificNode(T key)
    {
        Node *temp = headptr;
        int counter = 1;
        if (headptr == NULL)
        {
            cout << "List Empty !" << endl;
            return;
        }
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "Value |" << key << "| found at address |" << temp << "| on the index " << counter << endl;
            }
            temp = temp->next;
            counter++;
        }
        if (temp->next == NULL)
        {
            cout << "Element not found !" << endl;
        }
        return;
    }

    void DeleteSpecificNode(T key)
    {
        Node *current = headptr;
        Node *previous;
        int counter = 1;
        if (headptr == NULL)
        {
            cout << "List Empty !" << endl;
            return;
        }
        if (headptr->data == key)
        {
            headptr = headptr->next;
            cout << "Value |" << key << "| found at address |" << headptr << "| on the index 0 and deleted" << endl;
            return;
        }
        while ((current->next != NULL) && (current->data != key))
        {
            previous = current;
            current = current->next;
            counter++;
        }
        if (current->data == key)
        {
            cout << "Value |" << key << "| found at address |" << current << "| on the index " << counter << " and deleted" << endl;
            previous->next = current->next;
            delete current;
            return;
        }
        if (current->next == NULL)
        {
            cout << "Element not found !" << endl;
            return;
        }
        return;
    }

    bool Head()
    {
        return headptr->data;
    }

    bool SearchNode(T key)
    {
        Node *temp = headptr;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void BubbleSort()
    {
        Node *traverse = headptr;
        while (traverse != NULL)
        {
            Node *current = headptr;
            while (current != NULL)
            {
                if (current->value > traverse->value)
                {
                    T temp = current->value;
                    current->value = traverse->value;
                    traverse->value = temp;
                }
                current = current->next;
            }
            traverse = traverse->next;
        }
    }

    void removeDuplicate()
    {
        if (headptr == NULL)
        {
            return;
        }
        Node *temp = headptr;
        while (temp != NULL)
        {
            if (temp->data == temp->next->data)
            {
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
        return;
    }

    Node *reverse(Node *node)
    {
        if (node == NULL)
            return NULL;
        if (node->next == NULL)
        {
            headptr = node;
            return node;
        }
        Node *node1 = reverse(node->next);
        node1->next = node;
        node->next = NULL;
        return node;
    }

    int count()
    {
        Node *temp = headptr;
        int count = 0;
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ~LinkedList()
    {
        Node *previous;
        while (headptr != NULL)
        {
            previous = headptr;
            headptr = headptr->next;
            delete previous;
        }
    }
};
