/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* solve(TreeNode* node,TreeNode* p,TreeNode* q){
        if(node == NULL) return NULL;
        
        if(node == p || node == q) return node;
        
        TreeNode* left = solve(node->left,p,q);
        TreeNode* right = solve(node->right,p,q);
        
        if(left != NULL && right != NULL) return node;
        if(left != NULL) return left;
        return right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};