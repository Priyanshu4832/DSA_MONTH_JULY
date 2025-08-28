class Solution {
public:
    void sortDown(int r , int c , vector<vector<int>>& mat,vector<vector<int>>& copy ){

        //increasing
        int n = mat.size();
        vector<int> temp;
        int nr = r ;
        int nc  = c;
        while(nr>=0 && nr<n  && nc>=0 && nc<n){
            temp.push_back(mat[nr][nc]);
            
            nr++;
            nc++;
        }
        sort(temp.begin(),temp.end(),greater<int>());
        nr = r ;
        nc  = c;
        int idx = 0;
        while(idx<temp.size()){
            copy[nr][nc]=temp[idx];
            idx++;
            
            nr++;
            nc++;
        }




    }
    void sortUp(int r , int c , vector<vector<int>>& mat,vector<vector<int>>& copy ){

        //increasing
        int n = mat.size();
        vector<int> temp;
        int nr = r ;
        int nc  = c;
        while(nr>=0 && nr<n  && nc>=0 && nc<n){
            temp.push_back(mat[nr][nc]);
            
            nr++;
            nc++;
        }
        sort(temp.begin(),temp.end());
        nr = r ;
        nc  = c;
        int idx = 0;
        while(idx<temp.size()){
            copy[nr][nc]=temp[idx];
            idx++;
            
            nr++;
            nc++;
        }




    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> copy = grid;
        
        for(int i = n-1 ; i>0 ; i--){
            int startRow = 0;
            sortUp(startRow,i,grid,copy);
        }
        
        for(int i = 0 ; i<n; i++){
            int startCol = 0;
            sortDown(i,startCol,grid,copy);
        }
        
        return copy;
    }
};

