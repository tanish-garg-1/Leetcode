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
    int find_sum(TreeNode* root, int& sum){
        if(root==NULL) return 0;
        int left=max(0,find_sum(root->left,sum));
        int right=max(0,find_sum(root->right,sum));
        sum=max(sum,left+right+root->val);
        return root->val+max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        find_sum(root,sum);
        return sum;
    }
};