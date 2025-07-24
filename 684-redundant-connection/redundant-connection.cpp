class DisjointSet {
    vector<int> rank,parent;
    int components;
public:
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        components=n;
        for(int i=0 ;i<=n ;i++){
            parent[i]=i;
            
        }
    }
    
    int findPar(int node){
        if(node==parent[node]){
            return node;
        }
        
        return parent[node]=findPar(parent[node]);
    }
    
    void UnionByRank(int u,int v){
        
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        
        if(ulp_u==ulp_v) return;
        components--;
        
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
            
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    int compo(){
        return components;
    }
  
    
    
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        DisjointSet ds(n);

        vector<int> ans(2);
        for(int i=0 ; i<edges.size() ; i++){
            if(ds.findPar(edges[i][0])==ds.findPar(edges[i][1])){
                ans[0]=edges[i][0];
                ans[1]=edges[i][1];
            }
            else{
                ds.UnionByRank(edges[i][0],edges[i][1]);
            }
        }
        return ans;
    }
};