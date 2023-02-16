#include <iostream>
using namespace std;

class BinarySearchTree
{
public:
    struct TreeNode
    {
        int value;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode *root;

    BinarySearchTree()
    {
        root = NULL;
    }

    void InsertNode(int num)
    {
        TreeNode *newnode = new TreeNode;
        TreeNode *nodeptr = new TreeNode;
        newnode->value = num;
        newnode->left = newnode->right = NULL;

        if (!root)
            root = newnode;
        else
        {
            nodeptr = root;
            while (nodeptr != NULL)
            {
                if (num < nodeptr->value)
                {
                    if (nodeptr->left)
                        nodeptr = nodeptr->left;
                    else
                    {
                        nodeptr->left = newnode;
                        break;
                    }
                }
                else if (num > nodeptr->value)
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
                    cout << "Duplicate value found in tree" << endl;
                    break;
                }
            }
        }
    }

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

    void deleteNode(int value, TreeNode *&nodePtr)
    {
        if (value < nodePtr->value)
            deleteNode(value, nodePtr->left);
        else if (value > nodePtr->value)
            deleteNode(value, nodePtr->right);
        else
            makeDeletion(nodePtr);
    }

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
        tempptr = nodeptr->right;
        while (tempptr->left)
            tempptr = tempptr->left;
        tempptr->left = nodeptr->left;
        tempptr = nodeptr;
        nodeptr = nodeptr->right;
        delete tempptr;
        return;
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

    TreeNode *kthSmallest(TreeNode *root, int &k)
    {
        static int count = 0;
        if (root == NULL)
            return NULL;
        TreeNode *left = kthSmallest(root->left, k);
        if (left != NULL)
            return left;
        count++;
        if (count == k)
            return root;
        return kthSmallest(root->right, k);
    }

    void printKthSmallest(Node *root, int k)
    {
        Node *res = kthSmallest(root, k);
        if (res == NULL)
            cout << "There are less than k nodes in the BST";
        else
            cout << "K-th Smallest Element is " << res->data;
    }

    TreeNode *kthLargest(TreeNode *root, int k)
    {
        static int count = 0;
        if (root == NULL)
            rerurn NULL;
        TreeNode *left = kthLargest(root->right, k);
        if (left != NULL)
            return left;
        count++;
        if (count == k)
            return root;
        return kthLargest(root->left, k);
    }

    void printKthLargest(Node *root, int k)
    {
        Node *res = kthSLargest(root, k);
        if (res == NULL)
            cout << "There are less than k nodes in the BST";
        else
            cout << "K-th Largest Element is " << res->data;
    }
    
    int getHalfCount(TreeNode *root)
    {
        if (root == 0)
            return NULL;
        int result;
        if ((root->left == NULL && root->right != NULL) ||
            (root->left != NULL && root->right == NULL))
            result++;
        result += (getHalfCount(root->left) + getHalfCount(root->right));
        return result;
    }

    void printHalfCount()
    {
        cout << "The number of half nodes is " << getHalfCount(root);
    }

    int getFullCount(TreeNode *root)
    {
        if (root == 0)
            return NULL;
        int result;
        if ((root->left != NULL && root->right != NULL) ||
            (root->left != NULL && root->right != NULL))
            result++;
        result += (getHalfCount(root->left) + getHalfCount(root->right));
        return result;
    }

    void printFullCount()
    {
        cout << "The number of full nodes is " << getFullCount(root);
    }


    void printBST(string prefix, TreeNode *node, bool isLeft)
    {
        if (node != nullptr)
        {
            cout << prefix;

            cout << (isLeft ? "|-" : "|__");

            cout << node->value << endl;

            printBST(prefix + (isLeft ? "|   " : "    "), node->left, true);
            printBST(prefix + (isLeft ? "|   " : "    "), node->right, false);
        }
    }

    void printBT(TreeNode *node)
    {
        printBST("", node, false);
    }

    
};

int main()
{
    BinarySearchTree b;
    b.InsertNode(4);
    b.InsertNode(3);
    b.InsertNode(1);
    b.InsertNode(8);
    b.InsertNode(5);
    b.InsertNode(2);
    b.InsertNode(7);
    b.printBT(b.root);
}