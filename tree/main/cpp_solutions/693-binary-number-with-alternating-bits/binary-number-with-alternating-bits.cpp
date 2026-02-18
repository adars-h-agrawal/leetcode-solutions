class Solution {
public:
    bool hasAlternatingBits(int n) {
        return (0x55555555>>(countl_zero((unsigned)n)-1))==n;
    }
};