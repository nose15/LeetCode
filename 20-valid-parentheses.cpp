class Solution {
public:
    bool isValid(string s) {
        stack<char> opened;

        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case '}':
                    if (opened.empty() || opened.top() != '{') return false;
                    opened.pop();
                    break;
                case ']':
                    if (opened.empty() || opened.top() != '[') return false;
                    opened.pop();
                    break;
                case ')':
                    if (opened.empty() || opened.top() != '(') return false;
                    opened.pop();
                    break;

                default:
                    opened.push(s[i]);
                    break;

            }
        }

        return opened.empty();
    }
};
