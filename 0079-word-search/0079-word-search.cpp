class Solution {
    vector<int>x = {-1,0,1,0};
    vector<int>y = {0,1,0,-1};
    bool find(int r,int c,int ind,vector<vector<char>>& board,string word){
        if(ind == word.length()) return true;
        
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() 
          || board[r][c] == '$'){
            return false;
        }
        
        if(board[r][c] != word[ind]) return false;
        
        char temp = board[r][c];
        board[r][c] = '$';
        
        for(int k=0;k < 4;k++){
            int nr = r + x[k];
            int nc = c + y[k];
            if(find(nr,nc,ind+1,board,word) == true) return true;
        }
        
        board[r][c] = temp; //backtrack
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i < n;i++){
            for(int j=0;j < m;j++){
                if(board[i][j] == word[0]){
                    if(find(i,j,0,board,word) == true) return true;
                }
            }
        }
        
        return false;
    }
};