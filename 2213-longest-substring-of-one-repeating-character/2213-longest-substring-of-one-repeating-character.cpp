class Solution {
public:
    struct Node {
        int pre, suf, best, len;
        char leftChar, rightChar;
    };
    
    vector<Node> tree;
    string s;
    
    Node merge(Node& L, Node& R) {
        Node res;
        res.len = L.len + R.len;
        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;
        
        res.pre = L.pre;
        if (L.pre == L.len && L.rightChar == R.leftChar) {
            res.pre += R.pre;
        }
        
        res.suf = R.suf;
        if (R.suf == R.len && R.leftChar == L.rightChar) {
            res.suf += L.suf;
        }
        
        res.best = max(L.best, R.best);
        if (L.rightChar == R.leftChar) {
            res.best = max(res.best, L.suf + R.pre);
        }
        
        return res;
    }
    
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = (start + end) / 2;
        build(2*node+1, start, mid);
        build(2*node+2, mid+1, end);
        tree[node] = merge(tree[2*node+1], tree[2*node+2]);
    }
    
    void update(int node, int start, int end, int idx, char val) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, val, val};
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2*node+1, start, mid, idx, val);
        else update(2*node+2, mid+1, end, idx, val);
        tree[node] = merge(tree[2*node+1], tree[2*node+2]);
    }
    
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        this->s = s;
        int n = s.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
        
        int k = queryCharacters.size();
        vector<int> result(k);
        
        for (int i = 0; i < k; i++) {
            s[queryIndices[i]] = queryCharacters[i];
            update(0, 0, n - 1, queryIndices[i], queryCharacters[i]);
            result[i] = tree[0].best;
        }
        
        return result;
    }
};