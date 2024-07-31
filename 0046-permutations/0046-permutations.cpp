class Solution {
    void solve(int ind,vector<vector<int>>&ans,vector<int>&freq,vector<int>&nums){
        if(ind >= nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=ind;i < nums.size();i++){
            if(freq[i] == 0){
                swap(nums[ind],nums[i]);
                solve(ind+1,ans,freq,nums);
                swap(nums[ind],nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>freq(nums.size(),0);
        
        solve(0,ans,freq,nums);
        return ans;
    }
};