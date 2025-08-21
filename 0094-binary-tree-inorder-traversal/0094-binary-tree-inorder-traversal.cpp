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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        vector<int> sol;
        while(curr!=NULL){
            if(curr->left ==NULL){
                sol.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* temp=curr;
                temp=temp->left;
                while(temp->right && temp->right!=curr){
                    temp=temp->right;
                }

                if(temp->right==NULL){
                    temp->right=curr;
                    curr=curr->left;
                }
                else{
                    temp->right=NULL;
                    sol.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return sol;
    }
};