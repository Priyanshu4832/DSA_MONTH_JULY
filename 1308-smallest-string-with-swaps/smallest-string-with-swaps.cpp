class DisjointSet {
    vector<int> rank,parent;

public:
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

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
  
  
    
    
};
class Solution {
public:
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        n = n-1;

        DisjointSet ds(n);

        for(auto it : pairs){
            ds.UnionByRank(it[0],it[1]);
        }

        unordered_map<int,vector<int>> hash;
        for(int i=0 ; i<s.size() ; i++){
            hash[ds.findPar(i)].push_back(i);
        }

        for(auto it : hash){
            vector<int> idx = it.second;
            string temp="";
            for(auto i : idx){
                temp+=s[i];
            }

            sort(idx.begin(),idx.end());
            sort(temp.begin(),temp.end());

            for(int i = 0 ; i<idx.size() ; i++){
                s[idx[i]]=temp[i];
            }
        }
        return s;
    }
};