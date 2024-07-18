class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       int n = nums.size();
        unordered_map<int,int>mp;
        mp[0] = 1;
        int sum = 0,ans = 0;
        for(int i=0;i < n;i++){
            sum += nums[i];
            // Edge case : if rem is -ve,add k to it,to make it +ve 
            int rem = sum%k < 0 ? sum%k + k : sum%k;
            if(mp.find(rem) != mp.end()){
                ans += mp[rem];
            }
            mp[rem]++;
        }
        
        return ans;
    }
};