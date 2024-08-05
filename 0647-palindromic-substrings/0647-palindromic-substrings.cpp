class Solution {
    bool dp[1001][1001]; //i,j -> changes
public:
    int cnt = 0;
    void check(string &s,int i,int j){
        //expand from center for each index
        while(i >= 0 && j < s.length() && s[i] == s[j]){
            cnt++;
            i--;
            j++;
        }
    }
    int countSubstrings(string s) {
        

        for(int i=0;i < s.length();i++){
            check(s,i,i);
            check(s,i,i+1);
        }
        return cnt;
        
//         int n = s.length();
//         memset(dp,-1,sizeof(dp));
//         int cnt = 0;
//         for(int L=1;L <= n;L++){
            
//             for(int i=0;i+L-1 < n;i++){
//                 int j = i + L - 1;
//                 if(i == j){
//                     dp[i][j] = true; //length 1 substring
//                 }
//                 else if(i+1 == j){
//                     dp[i][j] = s[i] == s[j]; //length 2 substring
//                 }
//                 else{
//                     dp[i][j] = (s[i] == s[j] && dp[i+1][j-1] == true);
//                 }
                
//                 if(dp[i][j] == true){
//                     cnt++;
//                 }
//             }
            
//         }
        
//         return cnt;
    }
};