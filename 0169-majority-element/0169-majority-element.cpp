class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore's algorithm -> majority cancel the effect of minority 
        int n = nums.size();
        
        int cnt = 0;
        int ele = -1;
        for(int i=0;i < n;i++){
            if(cnt == 0){
                ele = nums[i];
                cnt++;
            }
            else if(nums[i] == ele){
                cnt++;
            }
            else if(nums[i] != ele){
                cnt--;
            }
        }
        
        
        return ele;
    }
};