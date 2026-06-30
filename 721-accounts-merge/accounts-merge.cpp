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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjoint ds(n);
        unordered_map<string , int >mpp;
        for(int i = 0 ; i < n ; i++){
            for(int j = 1 ; j < accounts[i].size() ; j++){
                string mail = accounts[i][j];
                if(mpp.find(mail) == mpp.end()){
                    mpp[mail] = i;
                }
                else{
                    ds.ubs(i , mpp[mail]);
                }
            }
        }
        vector<vector<string>> mergedMail(n);
        for(auto it: mpp){
           string mail = it.first;
           int node = ds.find_ul_p(it.second);
           mergedMail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i = 0 ; i < n ; i++){
            if(mergedMail[i].size() == 0){
                continue;
            }
            sort(mergedMail[i].begin() , mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};