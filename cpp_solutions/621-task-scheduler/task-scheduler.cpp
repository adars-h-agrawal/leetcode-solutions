class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frq(26, 0);

        for (char c : tasks) {
            frq[c - 'A']++;
        }

        int maxFrq = *max_element(frq.begin(), frq.end());
        int countMax = 0;

        for (int f : frq) {
            if (f == maxFrq) countMax++;
        }

        return max((int)tasks.size(), (maxFrq - 1)*(n + 1)+countMax);
    }
};