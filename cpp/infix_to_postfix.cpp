#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
reference:
https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/
http://interactivepython.org/runestone/static/pythonds/BasicDS/InfixPrefixandPostfixExpressions.html
*/

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return -1;
}

string infixToPrefix(string infix)
{
    string res = "";
    stack<char> opestk;
    
    for (char c : infix)
    {
        if (c == ' ')
            continue;
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) 
            res += c;
        else if (c == '(')
            opestk.push(c);
        else if (c == ')')
        {
            while(!opestk.empty() && opestk.top() != '(')
            {
                res += opestk.top();
                opestk.pop();
            }
            if (!opestk.empty() && opestk.top() != '(')
                return ""; //invalid case
            else
                opestk.pop();
        }
        else
        {
            while(!opestk.empty() && precedence(c) <= precedence(opestk.top()))
            {
                res += opestk.top(); opestk.pop();
            }

            opestk.push(c);
        }
    }
    
    while (!opestk.empty())
    {
        res += opestk.top();
        opestk.pop();
    }
    
    return res;
}

int main()
{
    string tes = "( A + B ) * C - ( D - E ) * ( F + G )";
    string tes2 = "a+b*(c^d-e)^(f+g*h)-i";
    
    cout << "infix: " << tes2 << " \nto postfix: " << infixToPrefix(tes2);
    return 0;
}