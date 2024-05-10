class Solution {
public:

    string encode(vector<string>& strs) {
        string result;

        for (int i = 0; i < strs.size(); i++) {
            result += strs[i] + '\n';
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string temp;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '\n') {
                result.push_back(temp);
                temp = "";
                continue;
            }

            temp += s[i];
        }

        return result;
    }
};
