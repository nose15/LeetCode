// My original solution, ditched it because the memory efficiency was bad. Turns out it's the best one lol.
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        stack<int> indecesToMatch;
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {
            while (!indecesToMatch.empty() && temperatures[indecesToMatch.top()] < temperatures[i]) {
                int index = indecesToMatch.top();
                res[index] = i - index;
                indecesToMatch.pop();
            }

            indecesToMatch.push(i); 
        }

        return res;
    }
};

// My solution (pretty fast but not memory efficient)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        int index = 0;
        stack<int> indecesToMatch({0});
        vector<int> res(n, 0);

        for (int i = 1; i < n; i++) {
            index = indecesToMatch.top();

            while (!indecesToMatch.empty() && temperatures[index] < temperatures[i]) {
                res[index] = i - index;
                indecesToMatch.pop();

                if (indecesToMatch.empty()) break;
                index = indecesToMatch.top();
            }

            indecesToMatch.push(i); 
        }

        return res;
    }
};
