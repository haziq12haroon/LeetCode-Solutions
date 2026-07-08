class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        int n = s.size();
        
        vector<long long> sumD(n + 1, 0);
        vector<long long> cntN0(n + 1, 0);
        vector<long long> p(n + 1, 0);
        vector<long long> pow10(n + 1, 1);
        
        for (int i = 1; i <= n; ++i) {
            pow10[i] = pow10[i - 1] * 10 % MOD;
        }
        
        for (int i = 1; i <= n; ++i) {
            int d = s[i - 1] - '0';
            sumD[i] = sumD[i - 1] + d;
            cntN0[i] = cntN0[i - 1] + (d > 0 ? 1 : 0);
            p[i] = d ? (p[i - 1] * 10 + d) % MOD : p[i - 1];
        }
        
        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            long long n0 = cntN0[r + 1] - cntN0[l];
            long long sd = sumD[r + 1] - sumD[l];
            long long x = ((p[r + 1] - p[l] * pow10[n0]) % MOD + MOD) % MOD;
            ans.push_back((int)(x * sd % MOD));
        }
        
        return ans;
    }
};