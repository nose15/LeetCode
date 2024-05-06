class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> counts;

        for (int i = 0; i < nums.size(); i++) {
            if (counts.find(nums[i]) != counts.end()) {
                return true;
            }
            counts.insert(nums[i]);
        }

        return false;
    }
};
