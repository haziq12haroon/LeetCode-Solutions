class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask;
        
        for (auto& seat : reservedSeats) {
            int row = seat[0], col = seat[1];
            if (col >= 2 && col <= 9) {
                rowMask[row] |= (1 << (col - 2));
            }
        }
        
        int totalReservedRows = rowMask.size();
        int ans = (n - totalReservedRows) * 2;
        
        for (auto& [row, mask] : rowMask) {
            bool left = (mask & 0b000001111) == 0;   // seats 2-5
            bool mid = (mask & 0b000111100) == 0;    // seats 4-7
            bool right = (mask & 0b011110000) == 0;  // seats 6-9
            
            if (left && right) {
                ans += 2;
            } else if (left || mid || right) {
                ans += 1;
            }
        }
        
        return ans;
    }
};