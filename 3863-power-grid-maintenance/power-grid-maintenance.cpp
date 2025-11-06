class Solution {
public:

    class Disjoint{
        public:
        vector<int> parent, rank;

        Disjoint(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);

            for(int i=0 ; i<=n ; i++){
                parent[i]=i;
            }
        }

        int findPar(int node){
            if(node==parent[node]){
                return node;
            }
            return parent[node]=findPar(parent[node]);
        }

        void UnionByRank(int u , int v){
            int ulp_u = findPar(u);
            int ulp_v = findPar(v);

            if(ulp_u==ulp_v) return;

            if(rank[ulp_u]>rank[ulp_v]){
                parent[ulp_v]=ulp_u;
            }
            else if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u]=ulp_v;
            }
            else{
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }

    };
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        

        Disjoint ds(c);
        vector<int>res;

        for(auto it : connections){
            ds.UnionByRank(it[0],it[1]);
        }

        map<int,set<int>> mpp;
        for(int i=0 ; i<=c ; i++){
            int par = ds.findPar(i);
            mpp[par].insert(i);
        }

        for(auto it : queries){

        
            if(it[0]==1){

                int station = it[1];
                int par = ds.findPar(station);
       

         
                if(mpp[par].find(station)!=mpp[par].end()){
                    res.push_back(station);
                }
                else{
                    if(mpp[par].size()==0) res.push_back(-1);
                    else {
                        auto first = *mpp[par].begin();
                        res.push_back(first);
                    }
                }

                
            }

            else if(it[0]==2){
                int station = it[1];
                int par = ds.findPar(station);

                mpp[par].erase(station);
    

            }
        }

        return res;
    }
};