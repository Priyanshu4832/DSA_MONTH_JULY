class DisjointSet{
public:
vector<int> parent,rank;
int components;

    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        components=n+1;
        for(int i=0 ; i<=n ; i++) parent[i]=i;
    }
    

    int findPar(int node){
        if(node==parent[node]) return node;
        else return parent[node]=findPar(parent[node]);
    }
    void UnionByRank(int u , int v){

        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        
        if(ulp_u==ulp_v) return;

        components--;
        cout<<" node u "<<u<<" node v "<<v<<"components "<<components<<endl;

        if( rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else if( rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]=ulp_v;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size()<n-1) return -1;
        n=n-1;

        DisjointSet ds(n);
        int cnt=0;
        for(auto it : connections){
            if(ds.findPar(it[0])!=ds.findPar(it[1])){
                ds.UnionByRank(it[0],it[1]);
            }
            
        }
        int comp = ds.compo();
        return comp-1;

    }
};