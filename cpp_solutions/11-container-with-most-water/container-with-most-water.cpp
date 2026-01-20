class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, area = 0, maxA = 0;
        while (left < right) {
            int h = min(height[left], height[right]);
            int s = right - left;
            area = h * s;
            maxA = max(maxA, area);
            if (height[left] < height[right]) left++;
            else right--;
        }
        return maxA;
    }
};