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
    int ans=0;
    int hof_left(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(hof_left(root->left),hof_left(root->right));
    }
    int hof_right(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(hof_right(root->left),hof_right(root->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        diameterOfBinaryTree(root->left);
        ans=max(ans,hof_left(root->left)+hof_right(root->right));
        diameterOfBinaryTree(root->right);
        return ans;
        // int left_height=1+diameterOfBinaryTree(root->left);
        // int right_height=1+diameterOfBinaryTree(root->right);

        // return ans=max(ans,left_height+right_height-2);
    }
};