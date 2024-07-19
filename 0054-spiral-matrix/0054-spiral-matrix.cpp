class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row = matrix.size();
        int col = matrix[0].size();
        //track the count of ele. inserted 
        int cnt = 0;
        int total = row * col;
        int startRow = 0;
        int startCol = 0;
        int endRow = row-1;
        int endCol = col-1;
        while(cnt < total){
            for(int i=startCol;i <= endCol && cnt < total;i++){
                ans.push_back(matrix[startRow][i]);
                cnt++;
            }
            startRow++;
            for(int i=startRow;i <= endRow && cnt < total;i++){
                ans.push_back(matrix[i][endCol]);
                cnt++;
            }
            endCol--;
            for(int i=endCol;i >= startCol && cnt < total;i--){
                ans.push_back(matrix[endRow][i]);
                cnt++;
            }
            endRow--;
            for(int i=endRow;i >= startRow && cnt < total;i--){
                ans.push_back(matrix[i][startCol]);
                cnt++;
            }
            startCol++;
        }
        return ans;
    }
};