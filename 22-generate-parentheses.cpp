class Solution {
public:
    void generate(string curr, int leftToMatch, int leftToWrite, vector<string>& res) {
        if (leftToWrite == 0 && leftToMatch == 0) {
            res.push_back(curr);
            return;
        }

        if (leftToWrite > 0) {
            generate(curr + "(", leftToMatch + 1, leftToWrite - 1, res);
        }

        if (leftToMatch > 0) {
            generate(curr + ")", leftToMatch - 1, leftToWrite, res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate("(", 1, n - 1, res);
        return res;
    }
};
