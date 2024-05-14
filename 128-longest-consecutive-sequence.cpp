class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        unordered_set<int> numbers(nums.begin(), nums.end());

        int biggest_len = 0;
        for (int val : numbers) {
            int len = 1;
            if (!numbers.contains(val - 1)) {
                while (numbers.contains(val + len)) len++;
            }

            biggest_len = max(biggest_len, len);
        }

        return biggest_len;
    }


    // this turned out to be faster, but the first one is much better because it's simpler
    int longestConsecutive2(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        priority_queue<int> ints;
        int curr, prev;
        int biggest_len = 1;
        int len = 1;

        for (int i = 0; i < nums.size(); i++) {
            ints.push(nums[i]);
        }

        prev = ints.top(); ints.pop();

        while (!ints.empty()) {
            curr = ints.top(); ints.pop();

            if (!(curr >= prev - 1)) {
                if (len > biggest_len) {
                    biggest_len = len;
                }
                len = 0;
            }
            
            if (curr != prev)
                len++;
            prev = curr;
        }
        
        if (len > biggest_len) {
            biggest_len = len;
        }

        return biggest_len;
    }
};
