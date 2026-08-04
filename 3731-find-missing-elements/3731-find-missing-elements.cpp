class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        
        unordered_set<int> s(nums.begin(), nums.end());
        
        vector<int> ans;
        for (int x = mn + 1; x < mx; ++x) {
            if (!s.count(x)) {
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};