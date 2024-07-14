class Solution {
    vector<int> solve(vector<int>&nums,int target)
    {
        int n = nums.size();
        map<int,int>remSum;
        for(int i=0;i < n;i++)
        {
            remSum[nums[i]] = i;
        }

        for(int i=0;i < n;i++)
        {
            int rem = target-nums[i];

            if(remSum.find(rem) != remSum.end() && i != remSum[rem]) 
            {
                return {i,remSum[rem]};
            }
        }

        return {-1,-1};
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        return solve(nums,target);
        // set<int>s;

        // for(int i=0;i < nums.size();i++)
        // {
        //     s.insert(nums[i]);
        // }

        // for(int i=0;i < nums.size();i++)
        // {
        //     auto pos = 0;
        //     if(target < 0)
        //     {
        //         if(nums[i] > target){
        //              pos = s.find(target-nums[i]);
        //         }else{ pos = s.find(nums[i]-target);}
        //     }else{
        //         if(nums[i] < target){
        //              pos = s.find(target-nums[i]);
        //         }else{ pos = s.find(nums[i]-target);}
        //     }
        //     if(pos != s.end()){
        //         return {nums[i],pos};
        //     }
        // }
    }
};