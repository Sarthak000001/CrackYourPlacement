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
    bool solve(TreeNode* node,int ans,int targetSum){
        if(node == NULL) return false;
        
        if(node && node->left==NULL && node->right == NULL){
            ans += node->val;
            if(ans == targetSum) return true;
            return false;
        }
        
        ans += node->val;
        bool left = solve(node->left,ans,targetSum);
        bool right = solve(node->right,ans,targetSum);
        
        if(left || right) return true;
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        return solve(root,ans,targetSum);
    }
};