class Solution {
public:
    using state = tuple<int, int, int>;

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        

        priority_queue<state, vector<state>, greater<state>> pq;

     
       
        vector<vector<int>> dis(m, vector<int>(n,1e8));
     
        pq.push({0, 0, 0});
        dis[0][0]=0;

        while (!pq.empty()) {
            auto [cost, r, c] = pq.top();
            pq.pop();

            if(dis[r][c]<cost) continue;
            if (r == m - 1 && c == n - 1) return cost;
            


            int drow[5] = {0, 0, 0, 1, -1};
            int dcol[5] = {0, 1, -1, 0, 0};

            for(int i = 1 ; i<=4 ; i++){
                int nr = r +drow[i];
                int nc = c +dcol[i];


                if(nr<m && nc<n && nr>=0 && nc>=0 ){

                    int newCost = 1; 
                    if(grid[r][c]==i) newCost = 0;

                    if( (newCost + dis[r][c]) < dis[nr][nc]){
                        pq.push({newCost+dis[r][c],nr,nc});
                        dis[nr][nc]=newCost+dis[r][c];
             
                    }
                    
                    
                }
                

            }

            
        }
        return 0;
    }
};