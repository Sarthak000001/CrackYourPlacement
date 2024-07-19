class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = INT_MIN;
        int left = 0,right = n-1;
        while(left <= right){
            int width = right - left;
            int ht = min(height[right],height[left]);
            ans = max(ans,width*ht);
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }
};