class Solution {
public:
    bool check(int r , int c , vector<vector<char>>& board , char ch){
        //down
       

        int start = (r-(r%3));
        int end = (c-(c%3));
        int k = 0;
        int p = 0;
        
        for(int i = 0 ; i<9 ; i++ ){
        
            if(board[i][c]==ch) return false;
            if(board[r][i]==ch) return false;
            if(board[start+k][end+p]==ch) return false;

            if(i==2 || i==5) k++;
            p++;
            if(i==2 || i==5) p=p-3;
            

        }
        

    

        return true;


    }

    bool solveBoard(vector<vector<char>>& board){

        for(int i = 0 ; i<9 ; i++){
            for(int j = 0 ; j<9 ; j++){
                if(board[i][j]=='.'){
                    for(char c = '1' ; c<='9' ; c++){
                        
                        if(check(i,j,board,c)==true){
                            board[i][j]=c;
                            if(solveBoard(board)==true) return true;
                            else board[i][j]='.';
                        }
                        
                        
                        

                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solveBoard(board);
    }
};