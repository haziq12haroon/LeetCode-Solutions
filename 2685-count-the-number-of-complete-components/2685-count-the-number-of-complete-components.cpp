class Solution {
public:
    vector<int> parent, sz;
    
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            if (sz[rx] < sz[ry]) swap(rx, ry);
            parent[ry] = rx;
            sz[rx] += sz[ry];
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
        
        for (auto& e : edges) unite(e[0], e[1]);
        
        vector<int> nodeCount(n, 0), edgeCount(n, 0);
        
        for (int i = 0; i < n; ++i) {
            nodeCount[find(i)]++;
        }
        
        for (auto& e : edges) {
            edgeCount[find(e[0])]++;
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (find(i) == i) {
                long long nc = nodeCount[i];
                long long need = nc * (nc - 1) / 2;
                if (edgeCount[i] == need) ans++;
            }
        }
        
        return ans;
    }
};