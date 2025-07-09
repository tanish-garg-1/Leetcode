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
public:
    TreeNode* insertIntoBST(TreeNode* root, int data) {
        TreeNode* temp=new TreeNode(data);
        // temp->val=data;
        TreeNode* head=root;
        while(root){
            if(root->val > data && root->left==NULL) {root->left=temp;break;}
            else if(root->val < data && root->right==NULL) {root->right=temp;break;}
            if(root->val > data) root=root->left;
            else if(root->val < data)root=root->right;
        }
        if(head==NULL) return temp;
        return head;
    }
};