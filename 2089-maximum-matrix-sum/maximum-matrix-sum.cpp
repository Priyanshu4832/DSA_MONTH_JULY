class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        int cnt = 0 ;
        int  maxi = INT_MAX;
        long long sum = 0;
        for(int i = 0 ; i<matrix.size() ; i++){
            for(int j = 0 ; j<matrix[0].size() ; j++){
                if(matrix[i][j]<=0){
                    cnt++;
                   
                }
                maxi = min(maxi,abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
                
            }
        }
        cout<<cnt<<" "<<maxi;
        if(cnt%2==0) return sum;
       
        else return sum-2*1LL*maxi;
    }
};