class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        unordered_set<int>st;
        for(int i=0;i < n;i++){
            if(st.find(nums[i]) != st.end()){
                ans.push_back(nums[i]);
            }
            st.insert(nums[i]);
        }
        return ans;
    }
};