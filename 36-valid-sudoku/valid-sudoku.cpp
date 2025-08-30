class Solution {
public:

    bool check(int r , int c , vector<vector<char>>& board ){
        //down
        vector<int> col(10,0);
        for(int down = 0 ; down<9 ; down++ ){
        
            if(board[down][c]!='.'){
                int cellVal = board[down][c]-'0';
                if(col[cellVal]==1) return false;
                else col[cellVal]=1;
            }
            

        }
        //down
        vector<int> row(10,0);
        for(int right = 0 ; right<9 ; right++ ){
            if(board[r][right]!='.'){
                int cellVal = board[r][right]-'0';
                if(row[cellVal]==1) return false;
                else row[cellVal]=1;
            }
        }

        // that cell
        //choose top left corner cell for that box from r,c
        int start = (r-(r%3));
        int end = (c-(c%3));
        vector<int> cell(10,0);
        for(int i = start ; i<start+3 ; i++){
            for(int j = end ; j<end+3 ; j++){
                if(board[i][j]!='.'){
                    int cellVal = board[i][j]-'0';
                    if(cell[cellVal]==1) return false;
                    else cell[cellVal]=1;
                }
            }
        }

        return true;


    }
    bool isValidSudoku(vector<vector<char>>& board) {
        

        
        for(int i = 0 ; i<9 ; i++){
            for(int j = 0 ; j<9 ; j++){
                if(board[i][j]!='.'){
                    if(check(i,j,board) == false ) return false;
                }
            }
        }
        return true;
    }
};