class Solution {
public:
    char processStr(string s, long long k) {
        const long long INF = 1e15 + 1;

        int n = s.size();
        vector<long long> len(n);

        long long cur = 0;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if ('a' <= c && c <= 'z') {
                cur++;
            }
            else if (c == '*') {
                if (cur > 0) cur--;
            }
            else if (c == '#') {
                cur = min(INF, cur * 2);
            }
            else if (c == '%') {
                // length unchanged
            }

            len[i] = cur;
        }

        if (k >= cur) return '.';

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];

            long long before = (i == 0 ? 0 : len[i - 1]);

            if ('a' <= c && c <= 'z') {

                if (k == before)
                    return c;
            }
            else if (c == '*') {
                // index unchanged
            }
            else if (c == '#') {
                if (before > 0 && k >= before)
                    k -= before;
            }
            else if (c == '%') {
                if (before > 0)
                    k = before - 1 - k;
            }
        }

        return '.';
    }
};