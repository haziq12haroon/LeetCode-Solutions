class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int n = nums1.size();
        int m = nums2.size();
        int j = 0, k = 0;

        while (j < n && k < m) {
            if (nums1[j] <= nums2[k]) {
                res.push_back(nums1[j]);
                j++;
            } else {
                res.push_back(nums2[k]);
                k++;
            }
        }
        while (j < n) res.push_back(nums1[j++]);
        while (k < m) res.push_back(nums2[k++]);

        int tot = n + m;
        if (tot % 2 == 0) {
            int ind = tot / 2;
            return (res[ind] + res[ind - 1]) / 2.0;
        } else {
            return res[tot / 2];
        }
    }
};