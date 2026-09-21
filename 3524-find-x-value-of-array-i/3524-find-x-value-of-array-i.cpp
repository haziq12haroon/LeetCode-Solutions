class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k, 0), cur(k, 0);
        for (int a : nums) {
            vector<long long> nxt(k, 0);
            nxt[a % k] += 1;
            for (int r = 0; r < k; r++) {
                nxt[(r * (a % k)) % k] += cur[r];
            }
            cur = nxt;
            for (int r = 0; r < k; r++) res[r] += cur[r];
        }
        return res;
    }
};