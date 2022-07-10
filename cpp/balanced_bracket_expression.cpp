#include <stack>
#include <string>
#include <iostream>

using namespace std;

// https://www.hackerrank.com/challenges/ctci-balanced-brackets/problem

bool is_balanced(string exp) {
    stack<char> stck;
    for (char c : exp)
    {
        if (c == '{' || c == '[' || c == '(')
        {
            stck.push(c);
        }
        if (c == '}' || c == ']' || c == ')')
        {
            if (stck.empty())
                return false;
            
            char top = stck.top();
            stck.pop();
            
            if ((c == '}' && top != '{') ||
                (c == ']' && top != '[') ||
                (c == ')' && top != '('))
            {
                return false;
            }
        }
    }
    return stck.empty();
}

///////////////
int main()
{
    string exp = "{()}[{}]";

    if (is_balanced(exp))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
}