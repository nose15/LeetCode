class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 0);

        for (int i = 1; i < nums.size(); i++) {
            res[i] = nums[i - 1] * res[i - 1];
        }

        int postfix = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] *= postfix;
            postfix *= nums[i];
        }

        return res;
    }
};
