class Solution {
    bool dp[1001][1001]; //i,j -> changes
public:
    int countSubstrings(string s) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        int cnt = 0;
        for(int L=1;L <= n;L++){
            
            for(int i=0;i+L-1 < n;i++){
                int j = i + L - 1;
                if(i == j){
                    dp[i][j] = true; //length 1 substring
                }
                else if(i+1 == j){
                    dp[i][j] = s[i] == s[j]; //length 2 substring
                }
                else{
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1] == true);
                }
                
                if(dp[i][j] == true){
                    cnt++;
                }
            }
            
        }
        
        return cnt;
    }
};