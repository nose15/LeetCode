class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int area = 0;

        while (i < j) {
            area = max(min(height[i], height[j]) * (j - i), area);

            if (height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }

        return area;
    }
};
