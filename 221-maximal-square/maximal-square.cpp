class Solution {
public:

    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int flag=0;
 

        vector<vector<int>> down(m,vector<int>(n,0));


        for(int i=m-1 ; i>=0 ; i--){
            for(int j=n-1 ; j>=0 ; j--){
                if(flag==0 && matrix[i][j]=='1') flag=1;

                if(i==m-1){
                    if(matrix[i][j]=='1') down[i][j]=1;
                    else down[i][j]=0;
                }
                else{
                    if(matrix[i][j]=='1') down[i][j]=1+down[i+1][j];
                    else down[i][j]=0;
                }
                
                

                
             
            }
        }

        int maxSquare=0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                
                if(down[i][j]==0) continue;

                int startIdx = j;
                int downLen=down[i][j];

                for(int k = j+1 ; k<n ; k++){
                    if(matrix[i][k]=='1'){
                        downLen=min(downLen,down[i][k]);
                        if(downLen==k-j+1) maxSquare=max(downLen*downLen,maxSquare);
                    }
                    else break;
                }
            }
        }


        if(maxSquare==0 && flag==1) return 1;
        else return maxSquare;
   
    }
};