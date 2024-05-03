class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> prev_elements;

        for (int i = 0; i < nums.size(); i++) {
            if (prev_elements.find(target - nums[i]) != prev_elements.end()) {
                return {prev_elements[target - nums[i]], i};
            }

            prev_elements.insert({nums[i], i});
        }
        return {-1, -1};
    }
};
