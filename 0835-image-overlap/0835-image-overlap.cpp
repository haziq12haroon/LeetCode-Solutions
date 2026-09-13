class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<vector<int>> a(2 * n - 1, vector<int>(2 * n - 1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j]) {
                    for (int x = 0; x < n; x++) {
                        for (int y = 0; y < n; y++) {
                            if (img2[x][y]) {
                                a[i - x + n - 1][j - y + n - 1]++;
                            }
                        }
                    }
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < 2 * n - 1; j++) {
                ans = max(ans, a[i][j]);
            }
        }

        return ans;
    }
};