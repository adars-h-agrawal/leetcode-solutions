class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res;
        
        // Sign
        if ((numerator < 0) ^ (denominator < 0)) res += "-";
        
        // Convert to long to handle overflow
        long n = labs(numerator), d = labs(denominator);
        res += to_string(n / d);
        long rem = n % d;
        if (rem == 0) return res;

        res += ".";
        unordered_map<long, int> m;

        while (rem) {
            if (m.count(rem)) {
                res.insert(m[rem], "(");
                res += ")";
                break;
            }
            m[rem] = res.size();
            rem *= 10;
            res += to_string(rem / d);
            rem %= d;
        }
        return res;
    }
};