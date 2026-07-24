class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> dp = {0};
        
        for (int round = 0; round < 3; round++) {
            unordered_set<int> ndp;
            for (int x : nums) {
                for (int v : dp) {
                    ndp.insert(x ^ v);
                }
            }
            dp = ndp;
        }
        
        return dp.size();
    }
};