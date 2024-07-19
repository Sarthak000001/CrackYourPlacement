class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i < n;i++){
            int num = abs(nums[i]);
            int ind = num - 1;
            if(nums[ind] < 0) ans.push_back(num);
            else nums[ind] *= -1;
        }
        return ans;
    }
};