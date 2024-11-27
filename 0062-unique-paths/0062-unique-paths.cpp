#include <vector>
using namespace std;

class Solution {
    int function(int m, int n, int i, int j, vector<vector<int>>& arr) {

        if (i == m - 1 && j == n - 1) return 1;

        if (i >= m || j >= n) return 0;

        if (arr[i][j] != -1) return arr[i][j];

        arr[i][j] = function(m, n, i + 1, j, arr) + function(m, n, i, j + 1, arr);
        return arr[i][j];
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> arr(m, vector<int>(n, -1));
        return function(m, n, 0, 0, arr);
    }
};
