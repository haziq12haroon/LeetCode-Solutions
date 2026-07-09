class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> group(n);
        group[0] = 0;
        for (int i = 1; i < n; ++i) {
            group[i] = (nums[i] - nums[i - 1] > maxDiff) ? group[i - 1] + 1 : group[i - 1];
        }
        
        vector<bool> ans;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            ans.push_back(group[u] == group[v]);
        }
        return ans;
    }
};