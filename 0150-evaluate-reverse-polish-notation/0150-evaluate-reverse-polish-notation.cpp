class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        
        for (const auto &c: tokens) {
            if (c == "+") {
                int second = stack.top(); 
                stack.pop();
                int first = stack.top();
                stack.pop();
                stack.push(first + second);
            } else if (c == "-") {
                int second = stack.top(); 
                stack.pop();
                int first = stack.top();
                stack.pop();
                stack.push(first - second);                
            } else if (c == "*") {
                int second = stack.top(); 
                stack.pop();
                int first = stack.top();
                stack.pop();
                stack.push(first * second);                
            } else if (c == "/") {
                int second = stack.top(); 
                stack.pop();
                int first = stack.top();
                stack.pop();
                stack.push(static_cast<int>(static_cast<double>(first) / second));                
            } else {
                stack.push(stoi(c));
            }
        }
        
        return stack.top();
    }
};