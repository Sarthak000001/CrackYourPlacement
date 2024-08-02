class Solution {
    vector<int>dp;
    int solve(int n){
        //base case
        if(n <= 0) return 0;
        if(dp[n] != -1) return dp[n];
        int mini = n;
        for(int i=1;i*i <= n;i++){
            int sq = i*i;
            mini = min(mini,1 + solve(n-sq));
        }
        return dp[n] = mini;
    }
public:
    int numSquares(int n) {
        dp.resize(n+1,-1);
        return solve(n);
    }
};