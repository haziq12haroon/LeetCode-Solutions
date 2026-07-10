class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        const int LOG = 18;
        vector<pair<int,int>> sorted(n);
        for (int i = 0; i < n; ++i) sorted[i] = {nums[i], i};
        sort(sorted.begin(), sorted.end());
        
        vector<int> pos(n), val(n);
        for (int i = 0; i < n; ++i) {
            val[i] = sorted[i].first;
            pos[sorted[i].second] = i;
        }
        
        vector<vector<int>> up(LOG, vector<int>(n));
        int r = 0;
        for (int i = 0; i < n; ++i) {
            if (r < i) r = i;
            while (r + 1 < n && val[r + 1] - val[i] <= maxDiff) r++;
            up[0][i] = r;
        }
        
        for (int k = 1; k < LOG; ++k)
            for (int i = 0; i < n; ++i)
                up[k][i] = up[k - 1][up[k - 1][i]];
        
        vector<int> ans;
        for (auto& q : queries) {
            int u = pos[q[0]], v = pos[q[1]];
            if (u > v) swap(u, v);
            
            if (up[0][u] >= v) {
                ans.push_back(u == v ? 0 : 1);
                continue;
            }
            
            int cur = u, steps = 0;
            for (int k = LOG - 1; k >= 0; --k) {
                if (up[k][cur] < v) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }
            
            if (up[0][cur] >= v) {
                ans.push_back(steps + 1);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};