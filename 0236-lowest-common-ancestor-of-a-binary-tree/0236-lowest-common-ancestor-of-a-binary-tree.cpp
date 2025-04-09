/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool find_sol1(TreeNode* root, TreeNode* p,vector<TreeNode*>& p_v){
        if(root==NULL) return false;
        p_v.push_back(root);
        if(root==p) return true;
        if (find_sol1(root->left,p,p_v) || find_sol1(root->right,p,p_v)) return true;
        p_v.pop_back();
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_v,q_v;
        find_sol1(root,p,p_v);
        find_sol1(root,q,q_v);
        TreeNode* sol=NULL;
        for(int i=0;i<min(p_v.size(),q_v.size());i++){
            if(p_v[i]==q_v[i]) sol=p_v[i];
        }
        return sol;
    }
};