#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> balancer;

        for(char ch : s)
        {
            if (ch == '(' || ch == '[' || ch == '{') balancer.push(ch);
            else if (ch == ')' && !balancer.empty() && balancer.top() == '(') balancer.pop();
            else if (ch == ']' && !balancer.empty() && balancer.top() == '[') balancer.pop();
            else if (ch == '}' && !balancer.empty() && balancer.top() == '{') balancer.pop();
            else return false;
        }
        return balancer.empty();
    }
};
