class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ans = 0, i = 0;
        int pre = INT_MIN, mx = 0;
        
        while (i < n) {
            int j = i + 1;
            while (j < n && s[j] == s[i]) j++;
            int cur = j - i;
            
            if (s[i] == '1') {
                ans += cur;
            } else {
                mx = max(mx, pre + cur);
                pre = cur;
            }
            
            i = j;
        }
        
        ans += mx;
        return ans;
    }
};