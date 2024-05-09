class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        vector<int> res;

        // priority_queue allows for putting greatest values in front
        priority_queue<pair<int, int>> priorityQueue;

        for (int i = 0; i < nums.size(); i++) {
            counts[nums[i]]++; 
        }

        for (auto& it : counts) {
            // after inserting values to the priority queue, they are already sorted
            priorityQueue.push({it.second, it.first});

            // We want to perform this on last k iterations 
            // because the last k iterations will use the priority queue and insert the top value
            if (priorityQueue.size() > counts.size() - k) 
            {
                res.push_back(priorityQueue.top().second);
                priorityQueue.pop();
            }
        }
        
        return res;
    }
};
