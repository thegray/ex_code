/*
https://www.hackerrank.com/challenges/ctci-queue-using-two-stacks/problem

REFERENCE : 
https://www.geeksforgeeks.org/queue-using-stacks/
*/

#include <stack>

using namespace std;

class MyQueue 
{   
    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;   
        void push(int x) 
        {
            stack_newest_on_top.push(x);
        }

        void pop() 
        {
            if (stack_newest_on_top.empty() && stack_oldest_on_top.empty())
                return;
            if (stack_oldest_on_top.empty())
            {
                while(!stack_newest_on_top.empty())
                {
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
            }
            stack_oldest_on_top.pop();
        }

        int front() 
        {
            if (stack_newest_on_top.empty() && stack_oldest_on_top.empty())
                return -1;
            if (stack_oldest_on_top.empty())
            {
                while(!stack_newest_on_top.empty())
                {
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
            }
            return stack_oldest_on_top.top();
        }
};