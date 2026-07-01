class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }

        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == INT_MAX) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        priority_queue<tuple<int,int,int>> pq;
        pq.push({dist[0][0], 0, 0});
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        while (!pq.empty()) {
            auto [d, x, y] = pq.top(); pq.pop();
            if (x == n-1 && y == n-1) return d;
            if (visited[x][y]) continue;
            visited[x][y] = true;
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny])
                    pq.push({min(d, dist[nx][ny]), nx, ny});
            }
        }

        return -1;
    }
};