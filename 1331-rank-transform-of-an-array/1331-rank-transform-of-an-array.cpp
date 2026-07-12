class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        
        unordered_map<int, int> rank;
        for (int i = 0; i < sorted.size(); ++i) {
            rank[sorted[i]] = i + 1;
        }
        
        vector<int> ans(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            ans[i] = rank[arr[i]];
        }
        
        return ans;
    }
};