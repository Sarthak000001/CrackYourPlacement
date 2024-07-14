class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // floyd's algo
        int n = nums.size();
        int hare = nums[0]; 
        int tortoise = nums[0];
        while(1){
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
            if(tortoise == hare) break;
        }
        
        hare = nums[0];
        while(hare != tortoise){
            hare = nums[hare];
            tortoise = nums[tortoise];
        }
        return hare;
    }
};