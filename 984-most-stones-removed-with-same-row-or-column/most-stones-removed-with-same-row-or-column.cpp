class Disjoint {
    vector<int> size, parent;

public:
    Disjoint(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find_ul_p(int node){
        if(parent[node] == node) return node;
        return parent[node] = find_ul_p(parent[node]);
    }
    void ubs(int u , int v){
        int ul_u = find_ul_p(u);
        int ul_v = find_ul_p(v);
        if(ul_u == ul_v) return;
        if(size[ul_u] < size[ul_v]){
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u]; 
        }
        else{
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v]; 
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = -1;
        int maxCol = -1;
        for(auto it: stones){
            maxRow = max(maxRow , it[0]);
            maxCol = max(maxCol , it[1]);
        }
        Disjoint ds(maxRow + maxCol + 2);
        unordered_map<int,int>mpp;
        for(auto it: stones){
            int u = it[0];
            int v = it[1] + maxRow + 1;;
            ds.ubs(u,v);
            mpp[u] = 1;
            mpp[v] = 1;
        }
        int cnt = 0;
        for(auto it: mpp){
            int node = it.first;
            if(ds.find_ul_p(node) == node){
                cnt++;
            }
        }
        return n - cnt;
    }
};