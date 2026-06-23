class Solution {
public:
    static constexpr int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> up(m + 1), down(m + 1);

        // length = 2
        for (int i = 1; i <= m; i++) {
            up[i] = i - 1;
            down[i] = m - i;
        }

        for (int len = 3; len <= n; len++) {

            vector<int> pref(m + 1);

            // prefix of down
            for (int i = 1; i <= m; i++) {
                pref[i] = pref[i - 1] + down[i];
                if (pref[i] >= MOD) pref[i] -= MOD;
            }

            vector<int> nxtUp(m + 1);
            for (int i = 1; i <= m; i++) {
                nxtUp[i] = pref[i - 1];
            }

            // reuse pref for prefix of up
            fill(pref.begin(), pref.end(), 0);

            for (int i = 1; i <= m; i++) {
                pref[i] = pref[i - 1] + up[i];
                if (pref[i] >= MOD) pref[i] -= MOD;
            }

            vector<int> nxtDown(m + 1);
            int totalUp = pref[m];

            for (int i = 1; i <= m; i++) {
                nxtDown[i] = totalUp - pref[i];
                if (nxtDown[i] < 0) nxtDown[i] += MOD;
            }

            up.swap(nxtUp);
            down.swap(nxtDown);
        }

        long long ans = 0;

        if (n == 2) {
            for (int i = 1; i <= m; i++) {
                ans += up[i] + down[i];
            }
        } else {
            for (int i = 1; i <= m; i++) {
                ans += up[i];
                ans += down[i];
            }
        }

        return ans % MOD;
    }
};