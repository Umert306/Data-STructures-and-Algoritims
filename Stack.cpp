#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stack
{

public:
    vector<char> stack;
    int stackSize;
    int top;

    Stack(int size)
    {
        stack.resize(size);
        stackSize = 0;
        top = -1;
    }

    void Push(char value)
    {
        if (stack.size() == stackSize)
        {
            cout << "Stack is full!" << endl;
            return;
        }
        else
        {
            top++;
            stackSize++;
            stack[top] = value;
            return;
        }
    }

    char Pop(char val)
    {
        if (stack.empty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        else
        {
            cout << "Hello" << endl;
            //cout << "a" << stack[top] << endl;
            val = stack[top];
            stack.resize(stackSize - 1);
            stackSize--;
            top--;
            return val;
        }
    }

    void Display()
    {
        for (int i = stackSize - 1; i >= 0; i--)
            cout << "|" << stack[i] << "|" << endl;
        cout << endl;
    }

    bool checkEmpty()
    {
        if(stack.empty())
            return true;
        else
            return false;
    }

    friend bool isOperator(char);
    friend bool isOperand(char);
    friend int operatorClassification(char);
    friend string infixToPostfix(string);
};

bool isOperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
        return true;

    return false;
}

bool isOperand(char c)
{
    if (c >= 'A' && c <= 'Z')  
        return true;
    if (c >= 'a' && c <= 'z')  
        return true;
    if (c >= '0' && c <= '9')  
        return true;
    return false;
}

int operatorClassification(char c)
{

    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// bool isRightAssociative(char op)
// {
//     if (op == '^')
//         return true;
//     else
//         return false;
// }

bool precedenceChecker(char op1, char op2)
{
    int p1 = operatorClassification(op1);
    int p2 = operatorClassification(op1);
    if (p1 == p2)
    {
        if (op1 == '^')
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return (p1 > p2 ? true : false);
}

string infixToPostfix(string str)
{
   
}

int main()
{
    string str = "a+b*c-d";
    
    //s.Display();

    //string str = "a+b";
    cout << infixToPostfix(str);
}