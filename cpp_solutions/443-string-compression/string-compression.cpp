class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> ans;
        int count = 1, n = chars.size();

        for (int i = 1; i <= n; i++) {
            if (i < n && chars[i] == chars[i - 1]) count++;
            else {
                ans.push_back(chars[i - 1]);
                if (count > 1) {
                    string countStr = to_string(count);
                    ans.insert(ans.end(), countStr.begin(), countStr.end());
                }
                count = 1;
            }
        }
        chars = ans;
        return chars.size();
    }
};