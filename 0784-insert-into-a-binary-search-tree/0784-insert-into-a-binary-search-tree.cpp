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
    void functionn(TreeNode* root, int data){
        if(root==NULL){
            root=new TreeNode(data); 
            return;
        }
        if(data>root->val) insertIntoBST(root->right,data);
        else insertIntoBST(root->left,data);
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int data) {
        if(root==NULL) return new TreeNode(data); 
        if(data>root->val) root->right=insertIntoBST(root->right,data);
        else root->left=insertIntoBST(root->left,data);
        return root;
    }
};