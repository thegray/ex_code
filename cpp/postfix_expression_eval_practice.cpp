#include <bits/stdc++.h>

using namespace std;

double evaluatePostfix(string exp)
{
    stack<double> sta;

    for (char c : exp)
    {
        if (c >= '0' && c <= 9)
        {
            sta.push(c - '0'); //convert char to int in a very nice way
        }
        else
        {
            int op1 = sta.top(); sta.pop();
            int op2 = sta.top(); sta.pop();

            if (c == '+')
                sta.push(op2 + op1);
            else if (c == '-')
                sta.push(op2 + op1);
            else if (c == '*')
                sta.push(op2 * op1);
            else if (c == '/')
                sta.push(op2 / op1);
        }
    }

    return sta.top();
}