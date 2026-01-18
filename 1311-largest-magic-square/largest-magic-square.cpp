class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
     
        int k = min(m,n);

        for( k ; k>=1 ; k--){

            for(int vertical = 0 ; vertical<=m-k ; vertical++ ){
                for(int horizontal = 0 ; horizontal<=n-k ; horizontal++){

             
                   

                    int magicSum = 0;
                    int s1 = 0;
                    int s2 = 0;
                    for(int i = 0 ; i<k ; i++){
                        s1+= grid[vertical+i][horizontal+i];
                        
                        s2+= grid[vertical+i][horizontal+k-1-i];
                        
                    }
                    if(s1==s2) magicSum = s1;
                    else continue;

                    bool brokeOut= false;
                    for(int i = 0 ; i< k ; i++){

                        int s3 = 0;
                        int s4 = 0;
                        for(int j = 0 ; j<k ; j++){

                            s3 += grid[vertical+i][horizontal+j];
                            s4 += grid[vertical+j][horizontal+i];
                        }
                        if(s3!=s4 || s3!=magicSum ){
                            brokeOut = true;
                            break;
                        }
                        
                    }
                    if(brokeOut!=true) return k;



                }
            }
        }
        return 1;
    
    }
};