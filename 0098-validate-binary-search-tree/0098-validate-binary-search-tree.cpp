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
    bool recursion(TreeNode* root,long min,long max){
        if(root==NULL) return true;
        if(root->val>=max || root->val<=min) return false;
        return (recursion(root->left,min,root->val) && recursion(root->right,root->val,max));
    }
public:
    bool isValidBST(TreeNode* root) {
        return recursion(root,-1e18, 1e18);
    }
};