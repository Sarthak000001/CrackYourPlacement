class Solution {
    void solve(int ind,vector<int>&curr,vector<vector<int>>&ans,vector<int>&nums){
        ans.push_back(curr);
        
        for(int i=ind;i < nums.size();i++){
            if(i > ind && nums[i] == nums[i-1]) continue;
            //pick
            curr.push_back(nums[i]);
            solve(i+1,curr,ans,nums);
            //not pick
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>>ans;
       vector<int>curr;
        sort(nums.begin(),nums.end());
       solve(0,curr,ans,nums);
        return ans;
    }
};