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
    int maxx=INT_MIN,minn=INT_MAX;
    int max_function(TreeNode* root){
        if(root==NULL) return 0;
        return max(1+max_function(root->left),1+max_function(root->right));
    }
    int min_function(TreeNode* root){
        if(root==NULL) return 0;
        return min(1+min_function(root->left),1+min_function(root->right));
    }

    int check_height(TreeNode* root){
        if(root==NULL) return 0;
        int left_height=check_height(root->left);
        if(left_height==-1) return -1;
        int right_height=check_height(root->right);
        if(right_height==-1) return -1;

        if(abs(left_height-right_height)>1) return -1;
        return 1+max(left_height,right_height);
    }
public:
    bool isBalanced(TreeNode* root) {


        if(check_height(root)==-1) return false;
        return true;

    }
};