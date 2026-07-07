class Solution {
public:
    long long sumAndMultiply(int n) {
        long long p = 1, x = 0, s = 0;
        for (; n > 0; n /= 10) {
            int v = n % 10;
            s += v;
            if (v != 0) {
                x += p * v;
                p *= 10;
            }
        }
        return x * s;
    }
};