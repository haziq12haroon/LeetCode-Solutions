class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        for (auto& inv : invocations) {
            graph[inv[0]].push_back(inv[1]);
        }
        
        queue<int> q;
        q.push(k);
        vector<bool> seen(n, false);
        seen[k] = true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                if (!seen[v]) {
                    seen[v] = true;
                    q.push(v);
                }
            }
        }
        
        vector<int> ans;
        for (int u = 0; u < n; ++u) {
            if (seen[u]) continue;
            
            for (int v : graph[u]) {
                if (seen[v]) {
                    vector<int> all(n);
                    iota(all.begin(), all.end(), 0);
                    return all;
                }
            }
            
            ans.push_back(u);
        }
        
        return ans;
    }
};