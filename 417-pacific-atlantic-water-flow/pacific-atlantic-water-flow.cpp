class Solution {
public:
    
    void dfs(int r , int c ,int m , int n, vector<vector<int>>& heights , vector<vector<int>> &vis , vector<vector<pair<int,int>>> &canReach, int PA){

        vis[r][c]=1;
        cout<<"on cell "<<r<<" "<<c<<endl;
        if(PA==0){
            canReach[r][c].first=1;
        }
        else canReach[r][c].second=1;

        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        for(int i=0 ; i<4 ; i++){
            int nr = drow[i]+r;
            int nc = dcol[i]+c;
            if(nr>=0 && nc>=0 && nr<m && nc<n && vis[nr][nc]==0 && heights[nr][nc]>=heights[r][c]){
                dfs(nr,nc,m,n,heights,vis,canReach,PA);
            }
        }



    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> res;
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> viss(m,vector<int>(n,0));
        vector<vector<pair<int,int>>> canReach(m,vector<pair<int,int>>(n));

        //for Pacific
        for(int i=0 ; i<n ; i++){
            if(vis[0][i]==0) dfs(0,i,m,n,heights,vis,canReach,0);
        }
        for(int i=0 ; i<m ; i++){
            if(vis[i][0]==0) dfs(i,0,m,n,heights,vis,canReach,0);
        }

        //for Atlantic
        for(int i=0 ; i<n ; i++){
            if(viss[m-1][i]==0) dfs(m-1,i,m,n,heights,viss,canReach,1);
        }
        for(int i=0 ; i<m ; i++){
            if(viss[i][n-1]==0) dfs(i,n-1,m,n,heights,viss,canReach,1);
        }

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(canReach[i][j].first==1 && canReach[i][j].second==1 ){
                    res.push_back({i,j});
                }
            }
        }
        return res;

    }
};