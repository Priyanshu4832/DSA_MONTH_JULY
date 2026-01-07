
class DisjointSet {
    public:
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0 ; i<n ; i++) parent[i]=i;
    }

    int findPar(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findPar(parent[node]);
    }

    void UnionByRank(int u , int v){

        int ult_u = findPar(u);
        int ult_v = findPar(v);
        if(ult_u==ult_v) return;
        if(rank[ult_u]>rank[ult_v]){
            parent[ult_v]=ult_u;
        }
        else if(rank[ult_u]<rank[ult_v]){
            parent[ult_u]=ult_v;
        }
        else{
            parent[ult_v]=ult_u;
            rank[ult_u]+=1;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cables = connections.size();
        if(cables<n-1) return -1;
        
        
        DisjointSet ds(n);

        int extra=0;
        int ultimate_parent = -1;
        set<int> parents;
        for(auto it : connections){
            if(ds.findPar(it[0])==ds.findPar(it[1])) extra++;
            else{
                ds.UnionByRank(it[0],it[1]);
                parents.insert(ds.findPar(it[0]));
            }
        }
        
        //for(auto it : parents) cout<<it<<" ";
        //cout<<endl;
        int compo = parents.size();
        //cout<<"compo"<<compo<<endl;
        int leaf=0;
        for(int i=0 ; i<n ; i++){
            if(ds.findPar(i)==i) leaf++;
            //cout<<ds.findPar(i)<<" "<<i<<endl;
        }
        //cout<<"leaf "<<leaf<<endl;
        return leaf-compo+compo-1;
       
    }
};