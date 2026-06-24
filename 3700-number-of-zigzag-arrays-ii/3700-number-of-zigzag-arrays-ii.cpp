class Solution {
public:
    static constexpr long long MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        // Transition matrix M (0-indexed): M[i][k] = 1 if i + k >= m
        vector<vector<long long>> M(m, vector<long long>(m, 0));
        for (int i = 0; i < m; i++)
            for (int k = 0; k < m; k++)
                if (i + k >= m) M[i][k] = 1;

        auto mul = [&](vector<vector<long long>>& A, vector<vector<long long>>& B) {
            vector<vector<long long>> C(m, vector<long long>(m, 0));
            for (int i = 0; i < m; i++)
                for (int k = 0; k < m; k++) {
                    if (!A[i][k]) continue;
                    long long a = A[i][k];
                    for (int j = 0; j < m; j++)
                        C[i][j] = (C[i][j] + a * B[k][j]) % MOD;
                }
            return C;
        };

        // R = M^(n-2)  (n >= 3, so exponent >= 1)
        vector<vector<long long>> R(m, vector<long long>(m, 0));
        for (int i = 0; i < m; i++) R[i][i] = 1;
        long long e = n - 2;
        while (e > 0) {
            if (e & 1) R = mul(R, M);
            M = mul(M, M);
            e >>= 1;
        }

        // Base "up" vector for length 2: up[i] = i  (0-indexed)
        vector<long long> up(m);
        for (int i = 0; i < m; i++) up[i] = i;

        // answer = 2 * sum(R * up)
        long long sum = 0;
        for (int i = 0; i < m; i++) {
            long long v = 0;
            for (int k = 0; k < m; k++)
                v = (v + R[i][k] * up[k]) % MOD;
            sum = (sum + v) % MOD;
        }
        return (int)((2 * sum) % MOD);
    }
};