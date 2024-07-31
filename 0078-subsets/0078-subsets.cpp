class Solution {
    void generate(vector<int>nums,int index,vector<int>&output,vector<vector<int>>&ans){

        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }

        //not include ith ele.
        generate(nums,index+1,output,ans);
        int ele = nums[index];
        output.push_back(ele);
        //include ith ele..
        generate(nums,index+1,output,ans);
        output.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int index = 0;
        vector<int>output;
        vector<vector<int>>ans;
        generate(nums,index,output,ans);
        return ans;
    }
};