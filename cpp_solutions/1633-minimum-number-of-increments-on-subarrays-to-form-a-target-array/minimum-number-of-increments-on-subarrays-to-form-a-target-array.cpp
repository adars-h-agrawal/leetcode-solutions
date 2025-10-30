class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int operations = target[0]; // initial increments for the first element
        
        for (int i = 1; i < n; ++i) {
            if (target[i] > target[i - 1]) {
                operations += target[i] - target[i - 1];
            }
        }
        return operations;
    }
};