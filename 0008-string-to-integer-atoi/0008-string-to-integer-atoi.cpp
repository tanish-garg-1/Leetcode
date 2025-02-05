class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        bool positive = true;
        long long ans = 0;

        while (i < n && s[i] == ' ') i++;

        if (i < n && (s[i] == '-' || s[i] == '+')) {
            positive = (s[i] == '+');
            i++;
        }

        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            if (ans > INT_MAX) {
                return positive ? INT_MAX : INT_MIN;
            }
            
            i++;
        }

        return positive ? ans : -ans;
    }
};
