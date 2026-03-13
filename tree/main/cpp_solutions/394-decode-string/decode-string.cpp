class Solution {
public:
    string decodeString(string s) {
        stack<string> temps;
        stack<int> counts;
        string ans = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) k = k * 10 + (c - '0');
            else if (c == '[') {
                counts.push(k);
                temps.push(ans);
                ans = "";
                k = 0;
            }
            else if (c == ']') {
                int count = counts.top(); counts.pop();
                string temp = ans;
                ans = temps.top(); temps.pop();
                while (count-- > 0) {
                    ans += temp;
                }
            }
            else  ans += c;
        }
        return ans;
    }
};