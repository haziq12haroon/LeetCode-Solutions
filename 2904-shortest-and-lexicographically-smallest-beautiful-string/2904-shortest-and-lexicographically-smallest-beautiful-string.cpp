class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0, j = 0, cnt = 0;
        int n = s.size();
        string ans = "";
        
        while (j < n) {
            cnt += (s[j] == '1');
            
            while (cnt > k || (i < j && s[i] == '0')) {
                cnt -= (s[i] == '1');
                i++;
            }
            
            j++;
            
            if (cnt == k) {
                string t = s.substr(i, j - i);
                if (ans == "" || (int)t.size() < (int)ans.size() ||
                    ((int)t.size() == (int)ans.size() && t < ans)) {
                    ans = t;
                }
            }
        }
        
        return ans;
    }
};