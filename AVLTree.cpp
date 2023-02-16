#include <iostream>
using namespace std;

typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;

class AVLTree
{
    struct AVLNode
    {
        int element;
        int height;
        AVLNode *left;
        AVLNode *right;
    };

    int maxHeight(int a, int b)
    {
        if (a > b)
            return a;
        else
            return b;
    }

    AVLTree singleRotateWithLeft(Position k2)
    {
        Position k1;

        k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;

        k2->height = maxHeight(k2->left->height, k2->right->height) + 1;
        k1->height = maxHeight(k1->left->height, k2->height) + 1;

        return k1;
    }

    AVLTree singleRotateWithRight(Position k1)
    {
        Position k2;

        k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;

        k1->height = maxHeight(k1->left->height, k1->right->height) + 1;
        k2->height = maxHeight(k2->right->height, k1->height) + 1;

        return k2;
    }

    AVLTree doubleRotateWithLeft(Position k3)
    {
        k3->left = singleRotateWithRight(k3->left);
        return singleRotateWithLeft(k3);
    }

    AVLTree doubleRotateWithRight(Position k1)
    {
        k1->right = singleRotateWithLeft(k1->right);
        return singleRotateWithRight(k1);
    }

    AVLTree insertNode(int x, AVLTree t)
    {
        if (t == NULL)
        {
            t = new AVLNode;
            t->element = x;
            t->height = 0;
            t->left = t->right = NULL;
        }
        
        else if (x < t->element)
        {
            t->left = insertNode(x, t->left);

            if (t->left->height - t->right->height == 2)
            {
                if (x < t->left->element)
                    t = singleRotateWithLeft(t);

                else
                    t = doubleRotateWithLeft(t);
            }
        }

        else if (x > t->element)
        {
            t->right = insertNode(x, t->right);

            if (t->right->height - t->left->height == 2)
            {
                if (x > t->right->element)
                    t = singleRotateWithRight(t);

                else
                    t = doubleRotateWithRight(t);
            }
        }

        else
        {
            cout << "Duplicate value\n";
        }

        t->height = maxHeight(t->left->height, t->right->height) + 1;
        return t;
    }

    void showNodesInOrder()
    {
        displayInOrder(root);
        cout << endl;
    }

    void showNodesPreOrder()
    {
        displayPreOrder(root);
        cout << endl;
    }

    void showNodesPostOrder()
    {
        displayPostOrder(root);
        cout << endl;
    }

        void displayInOrder(TreeNode *nodeptr)
    {
        if (nodeptr)
        {
            displayInOrder(nodeptr->left);
            cout << nodeptr->value << endl;
            displayInOrder(nodeptr->right);
        }
        return;
    }

    void displayPreOrder(TreeNode *nodeptr)
    {
        if (nodeptr)
        {
            cout << nodeptr->value << endl;
            displayPreOrder(nodeptr->left);
            displayPreOrder(nodeptr->right);
        }
        return;
    }

    void displayPostOrder(TreeNode *nodeptr)
    {
        if (nodeptr)
        {
            displayPostOrder(nodeptr->left);
            displayPostOrder(nodeptr->right);
            cout << nodeptr->value << endl;
        }
        return;
    }
};
