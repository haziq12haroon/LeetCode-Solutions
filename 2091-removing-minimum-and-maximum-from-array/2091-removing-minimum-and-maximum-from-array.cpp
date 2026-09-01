class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        
        int lo = min(minIdx, maxIdx);
        int hi = max(minIdx, maxIdx);
        
        int fromFront = hi + 1;
        int fromBack = n - lo;
        int fromBoth = (lo + 1) + (n - hi);
        
        return min({fromFront, fromBack, fromBoth});
    }
};