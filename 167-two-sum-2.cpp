// My original solution, 98% runtime and 60% memory. But there's a better one
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = 1;
        int len = numbers.size();
        int prev = numbers[i];

        while (numbers[i] + numbers[j] != target) {
            if (j == len - 1) {
                i++;
                while(numbers[i] == prev) {
                    prev = numbers[i];
                    i++;
                }
                j = i + 1;
                continue;
            }
            
            j++;
        }

        return {i + 1, j + 1};
    }
};

// But this has a lower complexity because it's only one loop and the first one 
// although it doesnt have nested loops that would have time complexity O(n), it// acts like it
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum > target) {
                j--;
            }
            else if (sum < target) {
                i++;
            }
            else {
                return {i + 1, j + 1};
            }
        }

        return {i + 1, j + 1};
    }
};
