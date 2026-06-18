class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr = ((5*hour)%60 + minutes/12.0);
        double min=minutes;
        double sol=abs((hr-minutes)*6);
        if(sol<180) return sol;
        else return 360-sol;
    }
};