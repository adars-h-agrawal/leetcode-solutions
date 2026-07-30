class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;

        for (string t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                int result;

                if (t == "+") {
                    result = a + b;
                } else if (t == "-") {
                    result = a - b;
                } else if (t == "*") {
                    result = a * b;
                } else {
                    result = a / b;
                }
                stack.push(result);
            } else {
                stack.push(stoi(t));
            }
        }
        return stack.top();
    }
};