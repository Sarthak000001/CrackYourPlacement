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
    int solve(TreeNode* node,int low,int high){
        if(node == NULL) return 0;
        
        int left = solve(node->left,low,high);
        int right = solve(node->right,low,high); 
        
        return ((node->val < low || node->val > high) ?0 : node->val) + left + right;
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return solve(root,low,high);
    }
};