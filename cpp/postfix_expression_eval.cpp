#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int postfix_eval(string exp)
{
    stack<int> st;
    for (char c : exp)
    {
        if (isdigit(c))
            st.push(c - '0');
        else
        {
            int op1 = st.top(); st.pop();
            int op2 = st.top(); st.pop();
            if (c == '+') st.push(op2 + op1);
            else if (c == '-') st.push(op2 - op1);
            else if (c == '*') st.push(op2 * op1);
            else if (c == '/') st.push(op2 / op1);
            else if (c == '^') st.push(pow(op1, op2));
        }
    }
    return st.top();
}

int main()
{
    string exp = "231*+9-";
    cout << postfix_eval(exp) << endl;
    string ex2 = "25*9+3-";
    cout << postfix_eval(ex2) << endl;
    return 0;
}