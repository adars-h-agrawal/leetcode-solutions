class Solution {
public:
    int minimumPushes(string word) {
        int size = word.size();
        if (size <= 8) return size;

        int ans = 0, rem = size % 8, i = 1;
        size -= rem;
        while (size > 0) {
            size -= 8;
            ans += i * 8;
            i++;
        }
        ans += i * rem;
        return ans;
    }
};