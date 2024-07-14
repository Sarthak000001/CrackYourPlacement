class Solution {
public:
    void sortColors(vector<int>& nums) {
        // tc - O(n),sc - O(1)
        int n = nums.size();
        int low = 0,mid = 0,high = n-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }else{
                // mid pointing to 2
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
    }
};