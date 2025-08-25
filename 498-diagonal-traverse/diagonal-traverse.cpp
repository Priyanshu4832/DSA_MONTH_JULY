class Solution {
public:

    vector<int> func(int r , int c , vector<vector<int>>& mat , bool s ){
        vector<int> temp;
        int n = mat[0].size();
        int m = mat.size();
        while(r>=0 && r<m && c>=0 && c<n){
            temp.push_back(mat[r][c]);
            cout<<mat[r][c]<<" ";
            r--;
            c++;
        }
        cout<<endl;
        if(s==true){
            return temp;
        }
        else{
            reverse(temp.begin(),temp.end());
            return temp;
        }

    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        // create two array one for diagonal 

        int n = mat[0].size();
        int m = mat.size();


        vector<int> arr;
        
        bool s = true;
        for(int i = 0 ; i<m ; i++){
            int startCol = 0;
            vector<int> trav = func(i,startCol,mat,s);
            s=!s;
            for(auto it: trav) arr.push_back(it);
            cout<<"row and startcol is "<<i<<" "<<startCol<<endl;


        }
        for(int i = 1 ; i<n ; i++){
            int startRow = m-1;
            vector<int> trav = func(startRow,i,mat,s);
            s=!s;
            for(auto it: trav) arr.push_back(it);
            cout<<"startrow and col is "<<startRow<<" "<<i<<endl;

        }
        return arr;
        

    }
};