class Solution {
    // buy -> 1 & buy -> 0 (sell)
    int solve(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp){
        if(ind >= prices.size()){
            return 0;
        }
        if(dp[ind][buy] != -1) return dp[ind][buy];
        long long maxProfit = 0;
        if(buy){
            // buy 
            maxProfit = max(-prices[ind] + solve(ind+1,0,prices,dp),
                           0 + solve(ind+1,1,prices,dp));
        }
        else{
            // sell 
            maxProfit = max(prices[ind] + solve(ind+2,1,prices,dp),
                           0 + solve(ind+1,0,prices,dp));
        }
        return dp[ind][buy] = maxProfit;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};