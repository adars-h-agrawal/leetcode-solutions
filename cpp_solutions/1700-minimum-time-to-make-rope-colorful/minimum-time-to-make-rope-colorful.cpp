class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int totalTime = 0;
        
        for (int i = 1; i < n; ++i) {
            if (colors[i] == colors[i - 1]) {
                // Remove the smaller one, keep the larger
                totalTime += min(neededTime[i], neededTime[i - 1]);
                
                // Update to keep the max time for next comparison
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }
        return totalTime;
    }
};