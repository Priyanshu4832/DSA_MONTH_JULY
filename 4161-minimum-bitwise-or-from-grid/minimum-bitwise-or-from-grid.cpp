class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans = 1<<30;
        int  m = grid.size();
        int  n = grid[0].size();


        for(int i=20 ; i>=0 ; i--){

            bool overall_found_zero = true;


            for(int j=0 ; j<m ; j++){
                // consider for this row i havent found out i bit as 0 number
                bool found_bit_zero = false;
                for(int k=0 ; k<n ; k++){

                    if(grid[j][k]==-1) continue;

                    if(  ((1<<i)&(grid[j][k])) == 0 ){
                        // this means i found i'th bit as 0 so break out
                        found_bit_zero = true;
                        break;
                    }
                    
                }
                // if i did not find a 0 bit at i'th then check no furhter answe will have one just move out
                if(found_bit_zero==false){
                    overall_found_zero = false;
                    break;
                }
            }

            
            if(overall_found_zero==true){
                // i found atleast one 0 bit in all rows
                // put 0 bit in ans and remove all the numbers with i'th bit as 1
                // no need as ans already has ero in place [[ans = ans | (1<<i)]];
                for(int j=0 ; j<m ; j++){
                    for(int k=0 ; k<n ; k++){

                        if(grid[j][k]==-1) continue;

                        if(  ((1<<i)&(grid[j][k])) != 0 ){
                            // this means i found i'th bit as 1 so turn it to -1
                            grid[j][k]=-1;
                          
                        }
                        
                    }

                }
            }
            else{
                // i found one row bit bit as 1 
                // no just put 1 in ans
                ans = ans | (1<<i);
            }
        }

        ans = ans & ~(1<<30);
        return ans;
    }
};