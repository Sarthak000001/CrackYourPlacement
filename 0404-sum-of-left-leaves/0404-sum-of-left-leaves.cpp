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
    int ans = 0;
    void solve(TreeNode* parent,TreeNode* node){
        if(node == NULL){
            return;
        }
        solve(node,node->left);
        if(parent && parent->left == node && node->left == NULL && node->right == NULL){
            ans += node->val;
        }
        solve(node,node->right);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        solve(NULL,root);
        return ans;
    }
};