
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        unordered_map<char, int> need;
        for (char c : t) need[c]++;

        unordered_map<char, int> have;

        int required  = need.size();
        int formed    = 0;

        int left      = 0;
        int bestStart = 0;
        int bestLen   = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
          
            char c = s[right];
            have[c]++;

            if (need.count(c) && have[c] == need[c])
                formed++;

            while (formed == required) {
                int windowLen = right - left + 1;

                if (windowLen < bestLen) {
                    bestLen   = windowLen;
                    bestStart = left;
                }

                char leftChar = s[left];
                have[leftChar]--;

                if (need.count(leftChar) && have[leftChar] < need[leftChar])
                    formed--;

                left++;
            }
        }
        if (bestLen == INT_MAX) {
            return "";
        }
        return s.substr(bestStart, bestLen);
    }
};