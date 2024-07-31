class Solution {
    void solve(int ind,vector<vector<int>>&ans,vector<int>&ds,int target,vector<int>&arr){

        if(target == 0){
            ans.push_back(ds);
            return;

        }
        //loop from ind to n ,not include same ele. more than once
        for(int i=ind;i < arr.size();i++){
            //don't include same element
            //don't include element from 0 to ind 
             //arr[i] greater than target then break
             if(i > ind && arr[i]==arr[i-1]) continue;
             if(arr[i] > target) break;
            ds.push_back(arr[i]);
            solve(i+1,ans,ds,target-arr[i],arr);
            ds.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        solve(0,ans,ds,target,candidates);
        return ans;
    }
};