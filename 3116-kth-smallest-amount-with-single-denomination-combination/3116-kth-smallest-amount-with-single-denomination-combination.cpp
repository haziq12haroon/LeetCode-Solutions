class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        long long lo = 1, hi = (long long)(*min_element(coins.begin(), coins.end())) * k;
        
        auto countLE = [&](long long x) -> long long {
            long long cnt = 0;
            for (int mask = 1; mask < (1 << n); ++mask) {
                long long lcmVal = 1;
                int bits = __builtin_popcount(mask);
                bool overflow = false;
                
                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << i)) {
                        long long g = __gcd(lcmVal, (long long)coins[i]);
                        long long newLcm = lcmVal / g * coins[i];
                        if (newLcm > x) {
                            overflow = true;
                            break;
                        }
                        lcmVal = newLcm;
                    }
                }
                
                if (overflow) continue;
                
                int sign = (bits % 2 == 1) ? 1 : -1;
                cnt += sign * (x / lcmVal);
            }
            return cnt;
        };
        
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countLE(mid) < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        return lo;
    }
};