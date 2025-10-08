class Solution {
public:

    int func(vector<vector<int>>& matrix, int target){

        int low=0;
        int high=matrix.size()-1;
        int result =-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(matrix[mid][0]>target){
                high = mid-1;
                
            }
            else {
                low=mid+1;
                result = mid;
            }
        }
        return result;
    }
    int func2(vector<vector<int>>& matrix, int target){

        int idx = func(matrix,target);
        cout<<idx;
        if(idx==-1) return false;
        int low=0;
        int high=matrix[idx].size()-1;
       

        while(low<=high){
            int mid = low + (high-low)/2;

            if(matrix[idx][mid]>target){
                high = mid-1;
                
            }
            else if(matrix[idx][mid]==target){
                return true;
            }
            else {
                low=mid+1;
                
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        

        

        return func2(matrix,target);
    }
};