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
    vector<int>v;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return v;
        v.push_back(root->val);
        if(root->left!=NULL)preorderTraversal(root->left);
        if(root->right!=NULL)preorderTraversal(root->right);
        return v;
    }
};