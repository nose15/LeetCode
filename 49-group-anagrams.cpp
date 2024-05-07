class Solution {
public:
    string countChars(string str) {
        string res(26, '0');

        for (int i = 0; i < str.length(); i++) {
            res[str[i] - 'a']++; 
        }

        return res;
    } 

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        for (int i = 0; i < strs.size(); ++i) {
            anagramGroups[countChars(strs[i])].push_back(strs[i]);
        }

        vector<vector<string>> strings;
        for (auto& pair : anagramGroups) {

            strings.push_back(pair.second);
        }

        return strings;
    }
};
