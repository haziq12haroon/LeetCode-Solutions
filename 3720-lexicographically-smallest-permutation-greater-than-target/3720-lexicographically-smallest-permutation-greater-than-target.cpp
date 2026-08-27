class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        
        int maxL = 0;
        for (int i = 0; i < n; i++) {
            int c = target[i] - 'a';
            if (cnt[c] > 0) {
                cnt[c]--;
                maxL = i + 1;
            } else break;
        }
        
        vector<int> remain = cnt;
        for (int L = maxL; L >= 0; L--) {
            if (L < n) {
                int tc = target[L] - 'a';
                int pick = -1;
                for (int c = tc + 1; c < 26; c++) {
                    if (remain[c] > 0) { pick = c; break; }
                }
                if (pick != -1) {
                    remain[pick]--;
                    string ans = target.substr(0, L);
                    ans += (char)('a' + pick);
                    for (int c = 0; c < 26; c++) {
                        ans += string(remain[c], (char)('a' + c));
                    }
                    return ans;
                }
            }
            if (L > 0) {
                remain[target[L - 1] - 'a']++;
            }
        }
        
        return "";
    }
};