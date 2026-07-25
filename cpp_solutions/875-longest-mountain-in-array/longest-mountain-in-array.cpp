class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0, temp = 1, n = arr.size();
        bool asc = true, des = false, climbed = false;

        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                if (des) {
                    // previous mountain ends
                    ans = max(ans, temp);
                    // start a new climb
                    temp = 2;
                    asc = true;
                    des = false;
                    climbed = true;
                } else {
                    temp++;
                    climbed = true;
                }
            }
            else if (arr[i] < arr[i - 1]) {
                if (!climbed) {
                    // no mountain without climb
                    temp = 1;
                    asc = true;
                    des = false;
                }
                else {
                    temp++;
                    asc = false;
                    des = true;
                }
            }                
            else { // equal elements
                if (des) {
                    ans = max(ans, temp);
                }
                temp = 1;
                asc = true;
                des = false;
                climbed = false;
            }
        }
        if (des) {
            ans = max(ans, temp);
        }
        return ans >= 3 ? ans : 0;
    }
};