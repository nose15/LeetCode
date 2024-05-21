class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> values;
        int a;

        for (auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                a = values.top(); 
                values.pop();  

                switch (token.at(0)) {
                    case '+':
                        values.top() += a;
                        break;
                    case '-':
                        values.top() -= a;
                        break;
                    case '*':
                        values.top() *= a;
                        break;
                    case '/':
                        values.top() /= a;
                        break;
                }

                continue;
            }

            values.push(stoi(token));
        }

        return values.top();
    }
};
