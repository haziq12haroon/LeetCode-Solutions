class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });
        
        vector<int> result(n);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && nums[idx[j + 1]] - nums[idx[j]] <= limit) {
                j++;
            }
            vector<int> positions(idx.begin() + i, idx.begin() + j + 1);
            sort(positions.begin(), positions.end());
            for (int k = i; k <= j; k++) {
                result[positions[k - i]] = nums[idx[k]];
            }
            i = j + 1;
        }
        
        return result;
    }
};