class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n;i++){
            if(i > 0 && nums[i] == nums[i-1])continue;
            int target = -(nums[i]);
            int left = i+1,right = n-1;
            while(left < right){
                if(nums[left] + nums[right] > target){
                    right--;
                }
                else if(nums[left] + nums[right] < target){
                    left++;
                }
                else{
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right-1] == nums[right]) right--;
                    if(nums[left] + nums[right] == target){
                        ans.push_back({nums[i],nums[left],nums[right]});
                    }
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};