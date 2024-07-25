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
    pair<bool,int> helper(TreeNode* node){
        if(node == NULL) return {true,0};
        if(node && node->left==NULL && node->right==NULL) return {true,1};
        pair<bool,int> left = helper(node->left);
        pair<bool,int> right = helper(node->right);
        
        bool balanced = left.first && right.first && abs(right.second - left.second) <= 1;
        
        return {balanced,1 + max(left.second,right.second)};
    }
public:
    bool isBalanced(TreeNode* root) {
        return helper(root).first;
    }
};