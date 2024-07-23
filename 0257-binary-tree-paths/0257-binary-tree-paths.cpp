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
    void solve(TreeNode* node,string curr,vector<string>&ans){
        if(node == NULL) return ;
        if(node->left == NULL && node->right == NULL){
            curr += to_string(node->val);
            ans.push_back(curr);
            return;
        }
        curr += to_string(node->val) + "->";
        solve(node->left,curr,ans);
        solve(node->right,curr,ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string curr = "";
        solve(root,curr,ans);
        return ans;
    }
};