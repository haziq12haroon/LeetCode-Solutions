class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        
        int oddChar = -1;
        int oddCount = 0;
        vector<int> halfCnt(26, 0);
        for (int c = 0; c < 26; c++) {
            halfCnt[c] = cnt[c] / 2;
            if (cnt[c] % 2 == 1) {
                oddChar = c;
                oddCount++;
            }
        }
        
        // A palindrome permutation of s exists only if at most one char has odd count.
        if (oddCount > 1) return "";
        
        int m = n / 2;
        bool odd = (n % 2 == 1);
        
        // Parity must match: even length -> no odd-count char; odd length -> exactly one.
        if (!odd && oddCount != 0) return "";
        if (odd && oddCount != 1) return "";
        
        vector<int> remain = halfCnt;
        int maxL = 0;
        for (int i = 0; i < m; i++) {
            int c = target[i] - 'a';
            if (remain[c] > 0) {
                remain[c]--;
                maxL = i + 1;
            } else break;
        }
        
        if (maxL == m) {
            string leftHalf = target.substr(0, m);
            string rightHalf = leftHalf;
            reverse(rightHalf.begin(), rightHalf.end());
            
            if (odd) {
                char midCh = 'a' + oddChar;
                if (midCh > target[m]) {
                    return leftHalf + midCh + rightHalf;
                } else if (midCh == target[m]) {
                    string targetSuffix = target.substr(m + 1);
                    if (rightHalf > targetSuffix) {
                        return leftHalf + midCh + rightHalf;
                    }
                }
            } else {
                string targetSuffix = target.substr(m);
                if (rightHalf > targetSuffix) {
                    return leftHalf + rightHalf;
                }
            }
        }
        
        vector<int> remain3 = halfCnt;
        for (int i = 0; i < maxL; i++) remain3[target[i] - 'a']--;
        
        int L = maxL;
        while (L > m - 1) {
            L--;
            if (L >= 0) remain3[target[L] - 'a']++;   // guard: avoid target[-1]
        }
        
        for (int i = L; i >= 0; i--) {
            int tc = target[i] - 'a';
            int pick = -1;
            for (int c = tc + 1; c < 26; c++) {
                if (remain3[c] > 0) { pick = c; break; }
            }
            if (pick != -1) {
                remain3[pick]--;
                string leftHalf = target.substr(0, i);
                leftHalf += (char)('a' + pick);
                for (int c = 0; c < 26; c++) {
                    leftHalf += string(remain3[c], (char)('a' + c));
                }
                string rightHalf = leftHalf;
                reverse(rightHalf.begin(), rightHalf.end());
                if (odd) {
                    return leftHalf + (char)('a' + oddChar) + rightHalf;
                }
                return leftHalf + rightHalf;
            }
            if (i > 0) {
                remain3[target[i - 1] - 'a']++;
            }
        }
        
        return "";
    }
};