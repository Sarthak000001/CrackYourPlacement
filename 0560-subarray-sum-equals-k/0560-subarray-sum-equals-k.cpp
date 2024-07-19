class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0] = 1;
        int ans = 0;
        int preSum = 0;
        for(int i=0;i  < n;i++){
            preSum += nums[i];
            int remove = preSum-k; //sum-k
            ans += mp[remove];
            mp[preSum]++;
        }
        return ans;
    }
};