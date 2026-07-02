class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MIN));
        priority_queue<tuple<int,int,int>> pq;

        int start = health - grid[0][0];
        dist[0][0] = start;
        pq.push({start, 0, 0});

        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        while (!pq.empty()) {
            auto [h, x, y] = pq.top(); pq.pop();
            if (h < dist[x][y]) continue;
            if (x == m-1 && y == n-1) return h >= 1;
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int nh = h - grid[nx][ny];
                    if (nh > dist[nx][ny]) {
                        dist[nx][ny] = nh;
                        pq.push({nh, nx, ny});
                    }
                }
            }
        }

        return false;
    }
};