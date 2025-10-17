class Solution {
public:
    int func(int i , int j , vector<vector<char>>& matrix , vector<vector<int>>& down){
        if(i>=matrix.size()) return 0;

        if(down[i][j]!=-1) return down[i][j];
       
        if(matrix[i][j]=='1') {
            return down[i][j]= 1+func(i+1,j,matrix,down);
        }
        return down[i][j]=0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int flag=0;
 

        vector<vector<int>> down(m,vector<int>(n,-1));


        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(flag==0 && matrix[i][j]=='1') flag=1;
                func(i,j,matrix,down);
            }
        }

        int maxSquare=0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                
                if(down[i][j]==0) continue;

                int startIdx = j;
                int downLen=down[i][j];

                for(int k = j+1 ; k<n ; k++){
                    if(matrix[i][k]!=0){
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