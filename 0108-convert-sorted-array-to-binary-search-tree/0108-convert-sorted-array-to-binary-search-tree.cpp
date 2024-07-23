/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* solve(TreeNode* node,vector<int>&nums,int low,int high){
        if(low > high) return NULL;
        
        int mid = low + (high-low)/2;
        node = new TreeNode(nums[mid]);
        
        node->left = solve(node->left,nums,low,mid-1);
        node->right = solve(node->right,nums,mid+1,high);
        
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* node = NULL;
       if(nums.size() == 0) return NULL;
        
        return solve(NULL,nums,0,nums.size()-1);
    }
};