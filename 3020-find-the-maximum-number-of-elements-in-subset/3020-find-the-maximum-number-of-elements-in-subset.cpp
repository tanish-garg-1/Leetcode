class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;

        for (int x : nums)
            cnt[x]++;

        int ans = 1;

        // Special case for 1
        if (cnt.count(1)) {
            if (cnt[1] % 2)
                ans = max(ans, cnt[1]);
            else
                ans = max(ans, cnt[1] - 1);
        }

        for (auto &[x, f] : cnt) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (true) {
                if (!cnt.count(cur))
                    break;

                // Only one copy -> can only be the center
                if (cnt[cur] == 1) {
                    len++;
                    break;
                }

                // Prevent overflow
                if (cur > 1000000000LL / cur ||
                    !cnt.count(cur * cur)) {
                    // No valid next square, so current becomes center
                    len++;
                    break;
                }

                // Use two copies (left & right)
                len += 2;
                cur *= cur;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};