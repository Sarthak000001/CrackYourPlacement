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
    int findD(TreeNode* node,int &maxi){
        if(node == NULL) return 0;
        
        int left = findD(node->left,maxi);
        int right = findD(node->right,maxi);
        maxi = max(maxi,left+right);
        
        return 1 + max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        findD(root,ans);
        return ans;
    }
};