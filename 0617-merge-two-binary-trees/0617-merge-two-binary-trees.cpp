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
    TreeNode* solve(TreeNode* node1,TreeNode* node2,TreeNode* node){
        if(node1 == NULL && node2 == NULL){
            return NULL;
        }
        if(node1 != NULL && node2 != NULL){
            node = new TreeNode(node1->val + node2->val);
            node->left = solve(node1->left,node2->left,node->left);
            node->right = solve(node1->right,node2->right,node->right);
        }
        if(node1 == NULL){
            node = new TreeNode(node2->val);
            node->left = solve(node1,node2->left,node->left);
            node->right = solve(node1,node2->right,node->right);
        }
        if(node2 == NULL){
            node = new TreeNode(node1->val);
            node->left = solve(node1->left,node2,node->left);
            node->right = solve(node1->right,node2,node->right);
        }
        
        return node;
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* node = NULL;
        return solve(root1,root2,node);
    }
};