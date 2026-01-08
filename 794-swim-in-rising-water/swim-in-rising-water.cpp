class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
      
       

        
        priority_queue< pair<int,pair<int,int>>  , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> >pq;
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;


        int res = 0;

        while(!pq.empty()){
            auto it = pq.top();
            int r = it.second.first;
            int c = it.second.second;
            int height = it.first;

            pq.pop();
            //res = max(res,height);
            if( r == n-1 && c ==n-1) {
                return height ;
            }
            

            int drow[4]={-1,0,1,0};
            int dcol[4]={0,1,0,-1};
            
            for(int i = 0 ; i<4 ; i++){
                int nr = r+drow[i];
                int nc = c+dcol[i];
                if(nr>=0 && nc>=0 && nr<n&& nc<n && vis[nr][nc]==0){
                    int maxHeight = max(height,grid[nr][nc]);

                    pq.push({maxHeight,{nr,nc}});
                    vis[nr][nc]=1;
                    
                    

                }
            }


        }
        return res;
    }
};