/**
 * @file Assignment2
 * @author Mohammad Umer Tayyab 2021306
 * @brief Conversion of infix expression to postfix expression using array based stack implementation
 */

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// Using template to cater to any data type
template <class x>
class Stack
{
private:
    x *array;
    int sizeOfStack;
    int top;

public:
    /**
     * @brief Construct a new Stack object
     *
     * @param size The size of the stack to construct
     */
    Stack(int size)
    {
        array = new x[size];
        sizeOfStack = size;
        top = -1;
    }

    /**
     * @brief Pushes a value into the stack
     *
     * @param value The value to be pushed
     */
    void Push(x value)
    {
        if (checkFull())
        {
            cout << "Stack is full!" << endl;
            return;
        }

        else
        {
            top++;
            array[top] = value;
            return;
        }
    }

    /**
     * @brief Pops the value at the top of the stack
     *
     * @return Char The popped value from the top of the stack
     */
    x Pop()
    {
        if (checkEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        else
        {
            x popedValue = array[top];
            top--;
            return popedValue;
        }
    }

    /**
     * @brief Displays the stack from top to bottom
     *
     */
    void Display()
    {
        for (int i = top; i >= 0; i--)
            cout << "|" << array[i] << "|" << endl;

        cout << endl;
    }

    /**
     * @brief Gets the value that is at the top of the stack
     *
     * @return Char The top value of the stack
     */
    char topGetter()
    {
        return array[top];
    }

    /**
     * @brief Checks if the stack is empty or not
     *
     * @return True If the stack is empty
     * @return False If the stack is not empty
     */
    bool checkEmpty()
    {
        if (top == -1)
            return true;

        else
            return false;
    }

    /**
     * @brief Checks if the stack is full or not
     *
     * @return true If the stack is full
     * @return false If the stack is empty
     */
    bool checkFull()
    {
        if (top == sizeOfStack - 1)
            return true;

        else
            return false;
    }
};

/**
 * @brief Checks if the input charater is an a or not
 *
 * @param C The input character
 * @return true If the charater is an operator
 * @return false If the charater is not an operator
 */
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;

    return false;
}

/**
 * @brief
 *
 * @param c The input character
 * @return true If input is a valid character
 * @return false If the input is not a valid character
 */
bool isValidSymbol(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == ')' || c == '(')
        return true;

    return false;
}

/**
 * @brief Checks if the character is an operand or not, example 1,2,3,a,b,c
 *
 * @param c The input character
 * @return true If the character is an operand
 * @return false If the character is not an operand
 */
bool isOperand(char c)
{
    if (c >= '0' && c <= '9')
        return true;

    return false;
}

/**
 * @brief Checks if the input character is a bracket or not
 *
 * @param c The input character to be checked
 * @return true If bracket is found
 * @return false If bracket not found
 */
bool isBracket(char c)
{
    if (c == '(' || c == ')')
        return true;

    else
        return false;
}

/**
 * @brief Classifies the operators by their precedence
 *
 * @param c The input charater
 * @return int The hierarchical level of the operaotr
 */
int operatorClassification(char c)
{
    if (c == '^')
        return 3;

    if (c == '/' || c == '*')
        return 2;

    else if (c == '+' || c == '-')
        return 1;

    else
        return -1;
}

/**
 * @brief Turns the infix expression to it's equivilant postfix expression
 *
 * @param inputEquation The input infix string to be converted
 * @return string The converted postfix expression
 */
string infixToPostfix(string inputEquation)
{
    int sizeOfInput = inputEquation.length();
    Stack<char> s(sizeOfInput);
    string result = "";

    for (int i = 0; i < sizeOfInput; i++)
    {
        // ignores all the subsequesnt operations to the paticular character in the input string
        if (inputEquation[i] == ' ')
            continue;

        if (isOperator(inputEquation[i]))
        {
            if (inputEquation[i] == ')' || inputEquation[i] == '(')
            {
                i = i + 1;
            }
            // pops the stack if an operator of higher precedence is found
            while (!s.checkEmpty() && (operatorClassification(inputEquation[i]) <= operatorClassification(s.topGetter())))
            {
                result = result + s.topGetter() + ' ';
                s.Pop();
            }
            s.Push(inputEquation[i]);
            // s.Push(' ');
        }

        // adds the operand to the result
        else if (isOperand(inputEquation[i]))
        {
            result = result + inputEquation[i];
            if (inputEquation[i + 1] != ' ')
            {
                result = result + inputEquation[i + 1];
                i = i + 1;
            }
            result = result + ' ';
        }

        else if (inputEquation[i] == '(')
        {
            s.Push(inputEquation[i]);
            // s.Push(' ');
        }

        // pushes the values till '(' when ')' encountered
        else if (inputEquation[i] == ')')
        {
            while (!s.checkEmpty() && s.topGetter() != '(')
            {
                result = result + s.topGetter();
                s.Pop();
            }
            s.Pop();
        }
    }

    // adds all the remaining operator in the stack to the result
    while (!s.checkEmpty())
    {
        result = result + s.topGetter();
        s.Pop();
    }

    return result;
}

// The five following functions are simple calculation functions
float Addition(float a, float b)
{
    return a + b;
}

float Subtraction(float a, float b)
{
    return a - b;
}

float Multiplication(float a, float b)
{
    return a * b;
}

float Division(float a, float b)
{
    return a / b;
}

float Exponent(float a, float b)
{
    return pow(a, b);
}

/**
 * @brief Checks if an opening bracket is contained then a closing bracket is also contained
 *
 * @param str The input string
 * @return true If both opening and closing brackets are contained
 * @return false If an opening brachet  is contained but the closing bracket is not
 */
bool bracketCheck(string str)
{
    int openBracket = 0;
    int closeBracket = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            openBracket += 1;

        if (str[i] == ')')
            closeBracket += 1;
    }

    if (closeBracket == openBracket)
        return true;

    else
        return false;
}

/**
 * @brief
 *
 * @param str The input string to be checked
 * @return true If the input string does not have any letters or invalid symbols
 * @return false If the input string has any letters or invalid symbols
 */
bool isValid(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!isOperand(str[i]) && !isValidSymbol(str[i]) && str[i] != ' ')
            return false;
    }
    return true;
}

/**
 * @brief Adds a space after every number and operator to ready the input string to be converted to postfix
 *
 * @param str The input string
 * @return string The fixed string
 */
string fixInputString(string str)
{
    string result;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            result += str[i];
            continue;
        }

        if (isOperand(str[i]) && isValidSymbol(str[i + 1]))
        {
            result += str[i];
            result += ' ';
        }

        else if (isValidSymbol(str[i]) && isOperand(str[i + 1]))
        {
            result += str[i];
            result += ' ';
        }

        else if (isValidSymbol(str[i]) && isValidSymbol(str[i + 1]))
        {
            result += str[i];
            result += ' ';
        }

        else
        {
            result += str[i];
        }
    }

    return result;
}

/**
 * @brief Evaluates a postfix expression mathamatically
 *
 * @param postfixExpression The input postfix expression
 * @return int The postfix expression's neumeric answer
 */
int evaluatePostfix(string postfixExpression)
{
    int sizeOfStack = postfixExpression.length();
    Stack<float> s(sizeOfStack);

    for (int i = 0; i < sizeOfStack; i++)
    {
        if (postfixExpression[i] == ' ')
        {
            continue;
        }

        if (isOperand(postfixExpression[i]))
        {
            if (postfixExpression[i + 1] != ' ')
            {

                string temp;
                temp += postfixExpression[i];
                temp += postfixExpression[i + 1];
                // stoi() used to convert a string to float
                s.Push(stof(temp));
                i = i + 1;
            }
            else
            {
                string temp;
                temp = postfixExpression[i];
                s.Push(stof(temp));
            }
        }

        if (isOperator(postfixExpression[i]))
        {
            char op = postfixExpression[i];
            float b = s.Pop();
            float a = s.Pop();
            if (op == '+')
            {
                s.Push(Addition(a, b));
            }
            else if (op == '-')
            {
                s.Push(Subtraction(a, b));
            }
            else if (op == '*')
            {
                s.Push(Multiplication(a, b));
            }
            else if (op == '/')
            {
                s.Push(Division(a, b));
            }
            else if (op == '^')
            {
                s.Push(Exponent(a, b));
            }
        }
    }
    return s.topGetter();
}

string infixToPrefix(string infix)
{
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.size();i++)
    {
        if(infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }
    sting prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

string prefixToPostfixViceVersa(string input)
{
    return reverse(input.begin(), input.end());
}

int main()
{
    string inputInfix;
    cout << "Enter the infix input to convert to postfix and evaluate : ";
    getline(cin, inputInfix);

    while (!bracketCheck(inputInfix))
    {
        cout << "Invalid input ! Check brackets" << endl;
        cout << "Enter again : ";
        getline(cin, inputInfix);
    }

    while (!isValid(inputInfix))
    {
        cout << "Invalid input ! Check any invalid letters" << endl;
        cout << "Enter again : ";
        getline(cin, inputInfix);
    }

    inputInfix = fixInputString(inputInfix);
    cout << "The postfix expression is : " << infixToPostfix(inputInfix) << endl;
    cout << "After evaluating the postfix expression the answer is : " << evaluatePostfix(infixToPostfix(inputInfix)) << endl;

    return 0;
}