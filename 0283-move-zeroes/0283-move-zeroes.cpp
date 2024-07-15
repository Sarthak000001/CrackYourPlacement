class Solution {
     // Snowball
     // idea is that we go through the array and gather all zeros on our road.
    void solve(vector<int>&nums){
        int snowSize = 0;
        for(int i=0; i< nums.size();i++){
            if(nums[i] == 0){
                snowSize++;
            }
            else if(snowSize > 0){
                int temp = nums[i];
                nums[i] = 0;
                nums[i-snowSize] = temp;
            }
        }
    }
public:
    void moveZeroes(vector<int>& nums) {
        solve(nums);
        // int n = nums.size();
        // int zero = 0,nzero = 0;
        // for(int i=0;i < n;i++){
        //     if(nums[nzero] == 0){
        //         nzero++;
        //     }
        //     else if(nums[zero] != 0){
        //         zero++;
        //         nzero++;
        //     }
        //     else{
        //         swap(nums[zero],nums[nzero]);
        //         zero++;
        //         nzero++;
        //     }
        // }
    }
};