class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans=(double)(30*hour-5.5*(double)(minutes));

        return min((360-abs(ans)),abs(ans));
    }
};