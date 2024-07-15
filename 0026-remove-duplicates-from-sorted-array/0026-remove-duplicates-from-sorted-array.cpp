class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0; 
        for(int i=0;i < n;i++){
            if(nums[ptr] != nums[i]){
                ptr++;
                nums[ptr] = nums[i];
            }
        }
        return ptr+1;
    }
};