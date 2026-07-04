class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]]; // path compression
            x = parent[x];
        }
        return x;
    }
    
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) parent[rx] = ry;
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
        
        vector<int> minWeight(n + 1, INT_MAX);
        
        for (auto& road : roads) {
            unite(road[0], road[1]);
        }
        
        for (auto& road : roads) {
            int u = road[0], v = road[1], w = road[2];
            int root = find(u);
            minWeight[root] = min(minWeight[root], w);
        }
        
        return minWeight[find(1)];
    }
};