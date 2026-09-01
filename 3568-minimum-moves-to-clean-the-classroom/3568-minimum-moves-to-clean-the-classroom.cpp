class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sx = 0, sy = 0, cnt = 0;
        vector<vector<int>> litterIdx(m, vector<int>(n, -1));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = classroom[i][j];
                if (c == 'S') {
                    sx = i; sy = j;
                } else if (c == 'L') {
                    litterIdx[i][j] = cnt++;
                }
            }
        }
        
        if (cnt == 0) return 0;
        
        int fullMask = (1 << cnt) - 1;
        
        vector<vector<vector<vector<bool>>>> vis(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << cnt, false))));
        
        queue<tuple<int,int,int,int>> q;
        q.push({sx, sy, energy, fullMask});
        vis[sx][sy][energy][fullMask] = true;
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        int steps = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                auto [x, y, curEnergy, mask] = q.front();
                q.pop();
                
                if (mask == 0) return steps;
                if (curEnergy <= 0) continue;
                
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (classroom[nx][ny] == 'X') continue;
                    
                    int nEnergy = curEnergy - 1;
                    int nMask = mask;
                    
                    if (classroom[nx][ny] == 'R') {
                        nEnergy = energy;
                    }
                    if (classroom[nx][ny] == 'L' && litterIdx[nx][ny] != -1) {
                        nMask &= ~(1 << litterIdx[nx][ny]);
                    }
                    
                    if (!vis[nx][ny][nEnergy][nMask]) {
                        vis[nx][ny][nEnergy][nMask] = true;
                        q.push({nx, ny, nEnergy, nMask});
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};