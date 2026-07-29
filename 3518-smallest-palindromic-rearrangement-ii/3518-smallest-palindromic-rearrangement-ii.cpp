class Solution {
public:
    const long long MAXV = 1000001;

    long long nCk(long long n, long long k) {
        long long res = 1;
        k = min(k, n - k);
        for (long long i = 1; i <= k; i++) {
            res = res * (n - i + 1) / i;
            if (res >= MAXV) return MAXV;
        }
        return res;
    }

    long long countArrangements(vector<int>& count) {
        long long total = 0;
        for (int c : count) total += c;
        long long res = 1;
        for (int freq : count) {
            res *= nCk(total, freq);
            if (res >= MAXV) return MAXV;
            total -= freq;
        }
        return res;
    }

    string smallestPalindrome(string s, long long k) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        int oddCount = 0;
        for (int c : cnt) if (c % 2 == 1) oddCount++;
        if (oddCount > 1) return "";

        vector<int> halfCount(26, 0);
        char midLetter = 0;
        for (int i = 0; i < 26; i++) {
            halfCount[i] = cnt[i] / 2;
            if (cnt[i] % 2 == 1) midLetter = 'a' + i;
        }

        long long totalPerm = countArrangements(halfCount);
        if (k > totalPerm) return "";

        int halfLen = 0;
        for (int c : halfCount) halfLen += c;

        string left = "";
        for (int pos = 0; pos < halfLen; pos++) {
            for (int i = 0; i < 26; i++) {
                if (halfCount[i] == 0) continue;

                halfCount[i]--;
                long long arrangements = countArrangements(halfCount);

                if (arrangements >= k) {
                    left += ('a' + i);
                    break;
                } else {
                    k -= arrangements;
                    halfCount[i]++;
                }
            }
        }

        string rev = left;
        reverse(rev.begin(), rev.end());

        string result = left;
        if (midLetter != 0) result += midLetter;
        result += rev;

        return result;
    }
};