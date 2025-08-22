class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();


        int top=100000;
        int bottom = -1;
        int left =10000;
        int right =-1;


        for(int i = 0 ; i<n ; i++){

            for(int j = 0 ; j<m ; j++){

                if(grid[j][i]==1){
                    left = min (left , i);
                    right = max(right , i);

                }
            }
        }
        for(int i = 0 ; i<m ; i++){

            for(int j = 0 ; j<n ; j++){

                if(grid[i][j]==1){
                    top = min (top , i);
                    bottom = max(bottom , i);

                }
            }
        }


        return (right-left+1)*(bottom-top+1);


    }
};