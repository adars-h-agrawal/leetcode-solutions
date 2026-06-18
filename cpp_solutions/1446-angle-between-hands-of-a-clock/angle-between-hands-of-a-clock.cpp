class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = hour % 12 * 30;
        h += double(minutes) / 60 * 30;
        double m = minutes % 60 * 6;
        return min(abs(h - m), 360 - abs(h - m));
    }
};