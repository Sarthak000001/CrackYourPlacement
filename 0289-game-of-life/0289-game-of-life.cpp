class Solution {
    // 8 direction 
    // -1,0
    //  -1,1
    //  0,1
    //  1,1
    //  1,0
    //  1,-1
    //  0,-1
    //  -1,-1
    int x[8] = {-1,-1,0,+1,+1,+1,0,-1};
    int y[8] = {0,+1,+1,+1,0,-1,-1,-1};
    int countNeighbour(vector<vector<int>>& board,int i,int j,int n,int m){
        int cnt = 0;
        for(int k=0;k < 8;k++){
            int nr = i + x[k];
            int nc = j + y[k];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && (board[nr][nc] == 1 || board[nr][nc] == 3)){
                cnt++;
            } 
        }
        
        return cnt;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        // original   new  state
        //     0       0   0
        //     1       0   1
        //     0       1   2
        //     1       1   3
        
        int row = board.size(),col = board[0].size();
        for(int i=0;i < row;i++){
            for(int j=0;j < col;j++){
                int ng = countNeighbour(board,i,j,row,col);//counting live neighbour
                if(board[i][j] == 1){
                    if(ng == 3 || ng == 2) board[i][j] = 3;
                }
                else{
                    //0
                    if(ng == 3) board[i][j] = 2;
                }
            }
        }
        
        
        for(int i=0;i < row;i++){
            for(int j=0;j < col;j++){
                if(board[i][j] == 1) board[i][j] = 0;
                else if(board[i][j] == 3 || board[i][j] == 2) board[i][j] = 1;
            }
        }
    }
};