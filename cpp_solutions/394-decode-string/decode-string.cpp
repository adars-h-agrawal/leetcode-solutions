class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> temps;
        string cur;
        int k; 

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                counts.push(k);
                temps.push(cur);
                cur = "";
                k = 0;
            } else if (c == ']') {
                string temp = cur;
                cur = temps.top(); temps.pop();
                int repeat = counts.top(); counts.pop();
                while (repeat-- > 0) {
                    cur += temp;
                }
            } else {
                cur += c;
            }
        }
        return cur;
    }
};