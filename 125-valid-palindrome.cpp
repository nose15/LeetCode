class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            while(i < j && !(isalpha(s[i]) || isdigit(s[i]))) i++;
            while(j > i && !(isalpha(s[j]) || isdigit(s[j]))) j--;

            if (tolower(s[i]) != tolower(s[j])) return false;
            
            i++;
            j--;
        }
        return true;
    }
};
