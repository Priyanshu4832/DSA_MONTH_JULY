class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> vis(m,vector<vector<int>>(n,vector<int>(k+1,0)));
        queue<  pair< pair<int,int> , pair<int,int>  >  > q;
        //row , col , step , remainin_k
        //q.push({ {} , {}  })
        q.push({ {0,0} , {0,k}  });
        vis[0][0][k]=1;


        while(!q.empty()){

            auto it = q.front();
            q.pop();

            int r = it.first.first;
            int c = it.first.second;
            int steps = it.second.first;
            int remain_k = it.second.second;

            if(r==m-1 && c==n-1) return steps;


            int drow[4]={-1,0,1,0};
            int dcol[4]={0,1,0,-1};
            for(int i = 0 ; i<4 ; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr>=m || nc>=n || nr<0 || nc<0) continue;
                //obstacle
                if(grid[nr][nc]==1 ){
                    if(remain_k>0 && vis[nr][nc][remain_k-1]==0){
                        q.push({ {nr,nc} , {steps+1,remain_k-1}  });
                        vis[nr][nc][remain_k-1]=1;
                    }
                }


                // no obstacle
                if(grid[nr][nc]==0 && vis[nr][nc][remain_k]==0 ){
                    
                    q.push({ {nr,nc} , {steps+1,remain_k}  });
                    vis[nr][nc][remain_k]=1;
                    
                }
            }
        }
        return -1;
    }
};