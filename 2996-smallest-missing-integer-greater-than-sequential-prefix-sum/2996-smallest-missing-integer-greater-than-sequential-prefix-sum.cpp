class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        
        int i = 1;
        while (i < n && nums[i] == nums[i - 1] + 1) {
            i++;
        }
        
        int prefixSum = 0;
        for (int j = 0; j < i; j++) {
            prefixSum += nums[j];
        }
        
        const int MAXV = 200;
        bool present[MAXV] = {false};
        
        for (int j = 0; j < n; j++) {
            if (nums[j] < MAXV) present[nums[j]] = true;
        }
        
        int x = prefixSum;
        while (x < MAXV && present[x]) {
            x++;
        }
        
        return x;
    }
};
