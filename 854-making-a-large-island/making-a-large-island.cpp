class Disjoint {
public:
    vector<int> parent, size;
    Disjoint(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int ultp(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = ultp(parent[node]);
    }
    void ubs(int u, int v) {
        int parent_u = ultp(u);
        int parent_v = ultp(v);

        if (parent_u == parent_v)
            return;
        if (size[parent_u] < size[parent_v]) {
            size[parent_v] += size[parent_u];
            parent[parent_u] = parent_v;
        } else {
            size[parent_u] += size[parent_v];
            parent[parent_v] = parent_u;
        }
    }
};
class Solution {
public:
    bool isValid(int row, int col, int n) {
        if (row >= 0 && row < n && col >= 0 && col < n) {
            return true;
        }
        return false;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        Disjoint ds(n * n);
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                for (int k = 1; k < 4; k++) {
                    int newR = i + dr[k];
                    int newC = j + dc[k];
                    if (isValid(newR, newC, n) && grid[newR][newC] == 1) {
                        int idx = (i * n) + j;
                        int curr_idx = n * newR + newC;
                        ds.ubs(idx, curr_idx);
                    }
                }
            }
        }

        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    continue;

                unordered_set<int> st;
                for (int k = 0; k < 4; k++) {
                    int newR = i + dr[k];
                    int newC = j + dc[k];
                    if(isValid(newR , newC,  n)){
                        if (grid[newR][newC] == 1) {
                            st.insert(ds.ultp(newR * n + newC));
                        }
                    }
                }
                int sum = 0;
                for (auto it : st) {
                    sum += ds.size[it];
                }
                mx = max(mx, sum + 1);
            }
        }
        for(int i = 0 ; i < n * n ; i++){
            mx = max(mx , ds.size[ds.ultp(i)]);
        }
        return mx;
    }
};