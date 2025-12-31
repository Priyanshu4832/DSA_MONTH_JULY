class DisjointSet {
    vector<int> rank,parent;
    int components;
public:
    DisjointSet(int n){
        rank.resize(n , 0);
        parent.resize(n);
     
        for(int i=0 ;i<n ;i++){
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
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        DisjointSet ds(row*col + 2);
        int top = row*col;
        int bottom = row*col+1;

        vector<vector<int>> mat(row , vector<int>(col , 1));

        for(int i=cells.size()-1 ; i>=0 ; i--){

            int r = cells[i][0]-1;
            int c = cells[i][1]-1;

            int dr[4]={-1,0,1,0};
            int dc[4]={0,1,0,-1};

            mat[r][c]=0;

            for(int k=0 ; k<4 ; k++){
                int nr = r+dr[k];
                int nc = c+dc[k];
                if(nr>=0 && nc>=0 && nr<row && nc<col && mat[nr][nc]==0){

                    int pos1 = nr*col + nc;
                    int pos2 = r*col + c;
                    ds.UnionByRank(pos1 , pos2);
                }
            }

            if(r==0) ds.UnionByRank(top , r*col + c);
            if(r==row-1) ds.UnionByRank(bottom , r*col + c);

            if(ds.findPar(top)==ds.findPar(bottom)){
                return i;
            }
            
        }
        return 0;
    }
};