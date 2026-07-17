class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> cnt(mx + 1, 0);
        vector<long long> cntG(mx + 1, 0);
        
        for (int x : nums) cnt[x]++;
        
        for (int i = mx; i >= 1; --i) {
            long long v = 0;
            for (int j = i; j <= mx; j += i) {
                v += cnt[j];
                cntG[i] -= cntG[j];
            }
            cntG[i] += v * (v - 1) / 2;
        }
        
        for (int i = 2; i <= mx; ++i) {
            cntG[i] += cntG[i - 1];
        }
        
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            long long x = queries[i];
            int lo = 0, hi = mx;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (cntG[mid] > x) hi = mid;
                else lo = mid + 1;
            }
            ans[i] = lo;
        }
        
        return ans;
    }
};