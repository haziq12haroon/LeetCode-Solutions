class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        
        string t = "";
        string mid = "";
        
        for (char c = 'a'; c <= 'z'; ++c) {
            int v = cnt[c - 'a'] / 2;
            if (v > 0) {
                t.append(v, c);
            }
            if (cnt[c - 'a'] % 2 == 1) {
                mid = string(1, c);
            }
        }
        
        string rev = t;
        reverse(rev.begin(), rev.end());
        
        return t + mid + rev;
    }
};