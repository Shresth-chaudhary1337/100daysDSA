/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <iostream>
#include <stack>
using namespace std;

// function to check operator precedence
int prec(char c)
{
    if(c=='+' || c=='-')
        return 1;
    if(c=='*' || c=='/')
        return 2;
    return 0;
}

int main()
{
    string infix;
    cin >> infix;

    stack<char> st;
    string postfix = "";

    for(int i=0;i<infix.length();i++)
    {
        char ch = infix[i];

        // if operand, add to postfix
        if(isalnum(ch))
        {
            postfix = postfix + ch;
        }

        // if opening bracket
        else if(ch=='(')
        {
            st.push(ch);
        }

        // if closing bracket
        else if(ch==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                postfix = postfix + st.top();
                st.pop();
            }
            st.pop();
        }

        // if operator
        else
        {
            while(!st.empty() && prec(st.top()) >= prec(ch))
            {
                postfix = postfix + st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // pop remaining operators
    while(!st.empty())
    {
        postfix = postfix + st.top();
        st.pop();
    }

    cout << postfix;
}