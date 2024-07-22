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
    void solve(TreeNode* node){
        if(node == NULL) return;
        
        swap(node->left,node->right);
        solve(node->left);
        solve(node->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        
        solve(root);
        return root;
    }
};