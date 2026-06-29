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
    int makeConnected(int n, vector<vector<int>>& arr) {
        if (arr.size() < n - 1)
            return -1;
        Disjoint ds(n);
        for (int i = 0; i < arr.size(); i++) {
            int u = arr[i][0];
            int v = arr[i][1];
            ds.ubs(u,v);
        }
        int cnt = 1;
        for(int i = 1 ;i < n ; i++){
            if(ds.find_ul_p(i-1) != ds.find_ul_p(i)){
                cnt++;
                ds.ubs(i-1 , i);
            }
        }
        return cnt - 1;
    }
};