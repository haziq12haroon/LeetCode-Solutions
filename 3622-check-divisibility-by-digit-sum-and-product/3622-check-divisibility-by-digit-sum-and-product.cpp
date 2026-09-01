class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0, digitProduct = 1;
        int x = n;
        
        while (x > 0) {
            int d = x % 10;
            digitSum += d;
            digitProduct *= d;
            x /= 10;
        }
        
        return n % (digitSum + digitProduct) == 0;
    }
};