class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = __gcd(nums[i], mx);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        
        long long ans = 0;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            ans += __gcd(prefixGcd[i], prefixGcd[j]);
        }
        return ans;
    }
};