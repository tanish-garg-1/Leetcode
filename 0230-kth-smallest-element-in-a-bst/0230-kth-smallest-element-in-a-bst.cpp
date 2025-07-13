class Solution {
    int result=-1;
        void inorder_trav(TreeNode* root, int& k){
        if(root==NULL) return ;
        inorder_trav(root->left,k);
        k=k-1;
        if(k==0) {result=root->val;return; }
        inorder_trav(root->right,k);
        }
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder_trav(root,k);
        return result;
    }
};


