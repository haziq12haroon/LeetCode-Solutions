class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + stoneValue[i];

        vector<vector<int>> dp(n, vector<int>(n, -1));

        function<int(int, int)> solve = [&](int i, int j) -> int {
            if (i == j) return 0;
            if (dp[i][j] != -1) return dp[i][j];
            int best = 0;
            for (int k = i; k < j; ++k) {
                int left = prefix[k + 1] - prefix[i];
                int right = prefix[j + 1] - prefix[k + 1];
                if (left < right) {
                    best = max(best, left + solve(i, k));
                } else if (left > right) {
                    best = max(best, right + solve(k + 1, j));
                } else {
                    best = max(best, left + solve(i, k));
                    best = max(best, right + solve(k + 1, j));
                }
            }
            return dp[i][j] = best;
        };

        return solve(0, n - 1);
    }
};