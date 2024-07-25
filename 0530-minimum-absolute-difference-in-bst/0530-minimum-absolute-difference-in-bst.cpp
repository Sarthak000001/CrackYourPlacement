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
    int ans = INT_MAX;
    void solve(TreeNode* node,TreeNode* &parent){
       if(node == NULL) return;
        
        solve(node->left,parent);
        
        if(parent!=NULL) ans = min(ans,abs(parent->val - node->val));
        parent = node;
       
        solve(node->right,parent);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        // Element's With Min. Diff. Would Be Next To Each Other,hence used
        // inorder traversal 
        TreeNode* node = NULL;
        solve(root,node);
        return ans;
    }
};