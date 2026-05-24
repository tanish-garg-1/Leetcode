class Solution {
public:
    vector<int> dp;
    int n, d;

    int dfs(int i, vector<int>& arr) {
        if (dp[i] != -1)
            return dp[i];

        int ans = 1;

        // explore left
        for (int j = i - 1; j >= max(0, i - d); j--) {
            if (arr[j] >= arr[i])
                break;

            ans = max(ans, 1 + dfs(j, arr));
        }

        // explore right
        for (int j = i + 1; j <= min(n - 1, i + d); j++) {
            if (arr[j] >= arr[i])
                break;

            ans = max(ans, 1 + dfs(j, arr));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        this->d = d;

        dp.assign(n, -1);

        int answer = 1;

        for (int i = 0; i < n; i++) {
            answer = max(answer, dfs(i, arr));
        }

        return answer;
    }
};