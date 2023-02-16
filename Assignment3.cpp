/**
 * @file Assignment3
 * @author Mohammad Umer Tayyab 2021306
 * @brief Binary Search Tree + , can include duplicate values in a BST
 */

#include <iostream>
using namespace std;

class BinarySearchTree
{

private:
    /**
     * @brief Provides the structure of a single node.
     *
     */
    struct TreeNode
    {
        int value;
        int counter = 0;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode *root;

    /**
     * @brief Utility fuction to delete a node
     *
     * @param nodeptr pointer of the node to delete
     */
    void makeDeletion(TreeNode *&nodeptr)
    {
        TreeNode *tempptr;
        if (!nodeptr)
        {
            cout << "Tree empty" << endl;
            return;
        }

        if (!nodeptr->right)
        {
            tempptr = nodeptr;
            nodeptr = nodeptr->left;
            delete tempptr;
            return;
        }

        if (!nodeptr->left)
        {
            tempptr = nodeptr;
            nodeptr = nodeptr->right;
            delete tempptr;
            return;
        }

        tempptr = tempptr->right;

        while (tempptr->left)
            tempptr = tempptr->left;

        tempptr->left = nodeptr->left;
        tempptr = nodeptr;
        nodeptr = nodeptr->right;
        delete tempptr;
        return;
    }

    /**
     * @brief Utility function to display in order
     *
     * @param nodeptr Pointer of the root node
     */
    void displayInOrder(TreeNode *nodeptr)
    {
        if (nodeptr)
        {
            displayInOrder(nodeptr->left);

            if (nodeptr->counter > 1)
            {
                for (int i = 0; i < nodeptr->counter; i++)
                    cout << nodeptr->value << " ";
            }

            else
            {
                cout << nodeptr->value << " ";
            }

            displayInOrder(nodeptr->right);
        }
        return;
    }

    /**
     * @brief Utility function to display pre order
     *
     * @param nodeptr Pointer of the root node
     */
    void displayPreOrder(TreeNode *nodeptr)
    {
        if (nodeptr)
        {

            if (nodeptr->counter > 1)
            {
                for (int i = 0; i < nodeptr->counter; i++)
                    cout << nodeptr->value << " ";
            }

            else
            {
                cout << nodeptr->value << " ";
            }

            displayPreOrder(nodeptr->left);
            displayPreOrder(nodeptr->right);
        }
        return;
    }

    /**
     * @brief Utility function to display post order
     *
     * @param nodeptr Pointer of the root node
     */
    void displayPostOrder(TreeNode *nodeptr)
    {
        if (nodeptr)
        {
            displayPostOrder(nodeptr->left);
            displayPostOrder(nodeptr->right);

            if (nodeptr->counter > 1)
            {
                for (int i = 0; i < nodeptr->counter; i++)
                    cout << nodeptr->value << " ";
            }

            else
            {
                cout << nodeptr->value << " ";
            }
        }
        return;
    }

    /**
     * @brief Utility function to find the node to delete
     *
     * @param value Value of the node to delete
     * @param nodeptr Root node for traversal
     */
    void deleteNode(int value, TreeNode *&nodeptr)
    {
        if (value < nodeptr->value)
            deleteNode(value, nodeptr->left);

        else if (value > nodeptr->value)
            deleteNode(value, nodeptr->right);

        else
        {
            if (nodeptr->counter > 1)
            {
                // decrements the counter of the duplicate node (if any)
                nodeptr->counter--;
                return;
            }

            else
            {
                makeDeletion(nodeptr);
                return;
            }
        }

        cout << "Node to delete not found" << endl;
    }

public:
    /**
     * @brief Construct a new Binary Search Tree object
     *
     */
    BinarySearchTree()
    {
        root = NULL;
    }

    /**
     * @brief Inserts a new value to the BST+
     *
     * @param newvalue The value of the node to add to the BST+
     */
    void insertNode(int newvalue)
    {
        TreeNode *newnode = new TreeNode;
        TreeNode *nodeptr = new TreeNode;
        newnode->value = newvalue;
        newnode->counter = 1;
        newnode->left = newnode->right = NULL;

        if (!root)
            root = newnode;

        else
        {
            nodeptr = root;
            while (nodeptr != NULL)
            {
                if (newvalue < nodeptr->value)
                {
                    if (nodeptr->left)
                        nodeptr = nodeptr->left;

                    else
                    {

                        nodeptr->left = newnode;
                        break;
                    }
                }
                else if (newvalue > nodeptr->value)
                {
                    if (nodeptr->right)
                        nodeptr = nodeptr->right;

                    else
                    {
                        nodeptr->right = newnode;
                        break;
                    }
                }
                else
                {
                    // Counter of the duplicate value incremented (if found)
                    nodeptr->counter++;
                    break;
                }
            }
        }
        cout << "Node added successfully" << endl;
    }

    /**
     * @brief Searches a number in the nodes of the BST+
     *
     * @param num Number to search in the BST+
     * @return true If node found.
     * @return  false If node not found
     */
    bool searchNode(int num)
    {
        TreeNode *nodeptr = root;
        while (nodeptr)
        {
            if (nodeptr->value == num)
                return true;

            else if (num < nodeptr->value)
                nodeptr = nodeptr->left;

            else
                nodeptr = nodeptr->right;
        }
        return false;
    }

    /**
     * @brief Accesses the utility function to traverse the BST+ to delete a node
     *
     * @param value The value of the nde in BST+ to delete
     */
    void removeNode(int value)
    {
        deleteNode(value, root);
        cout << "Node successfully removed" << endl;
    }

    /**
     * @brief Public function to display in order and access the private utility function
     *
     */
    void showNodesInOrder()
    {
        displayInOrder(root);
        cout << endl;
    }

    /**
     * @brief Public function to display pre order and access the private utility function
     *
     */
    void showNodesPreOrder()
    {
        displayPreOrder(root);
        cout << endl;
    }

    /**
     * @brief Public function to display post order and access the private utility function
     *
     */
    void showNodesPostOrder()
    {
        displayPostOrder(root);
        cout << endl;
    }
};

int main()
{
    BinarySearchTree b;
    int choice;
    while (true)
    {
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Node" << endl;
        cout << "4. Display in order" << endl;
        cout << "5. Display post order" << endl;
        cout << "6. Display pre order" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        if (choice == 7)
        {
            cout << "Exiting";
            break;
        }
        switch (choice)
        {
        case 1:
        {
            cout << "Enter node value to add to BST+ " << endl;
            int value;
            cin >> value;
            b.insertNode(value);
            break;
        }
        case 2:
        {
            cout << "Enter node to delete " << endl;
            int value;
            cin >> value;
            if (b.searchNode(value))
            {
                b.removeNode(value);
                break;
            }
            else
            {
                cout << "Node to delete not found" << endl;
                break;
            }
        }
        case 3:
        {
            cout << "Enter node to search " << endl;
            int value;
            cin >> value;
            if (b.searchNode(value))
            {
                cout << "Value found in tree" << endl;
            }
            else
            {
                cout << "Value not found in tree" << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Displaying in order : " << endl;
            b.showNodesInOrder();
            break;
        }
        case 5:
        {
            cout << "Displaying post order : " << endl;
            b.showNodesPostOrder();
            break;
        }
        case 6:
        {
            cout << "Displaying pre order : " << endl;
            b.showNodesPreOrder();
            break;
        }
        }
        // used to confirm to go back to the menu and clear unneeded clutter on the screen
        system("pause");
        system("cls");
    }
    return 0;
}