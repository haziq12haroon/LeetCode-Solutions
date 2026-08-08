class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> lookup(m, -1);
        for (int i = n - 1, j = m - 1; i >= 0; --i) {
            if (word1[i] != word2[j]) continue;
            lookup[j--] = i;
            if (j == -1) break;
        }
        vector<int> result;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            int k = result.size();
            if (!(word1[i] == word2[k] ||
                  (cnt == 0 && (k + 1 == m || i < lookup[k + 1])))) {
                continue;
            }
            if (word1[i] != word2[k]) ++cnt;
            result.push_back(i);
            if ((int)result.size() == m) return result;
        }
        return {};
    }
};