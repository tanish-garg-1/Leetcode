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
    TreeNode* recursion(int &i,vector<int>& preorder,int min,int max){
        if(i>=preorder.size()) return NULL;
        int val=preorder[i];
        if(val<min || val>max) return NULL;

        TreeNode* root=new TreeNode(preorder[i]);
        i++;
        root->left=recursion(i,preorder,min,val);
        root->right=recursion(i,preorder,val,max);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return recursion(i,preorder,INT_MIN,INT_MAX);
    }
};



// class Solution {
//     void create_tree(TreeNode* root,int &i,int min,int max,vector<int>& preorder){
//         if (i >= preorder.size()) return;
//         if(preorder[i]>min && preorder[i]<max) return ;
//         if(preorder[i]<min){
//             root->left=new TreeNode(preorder[i]);
//             i++;
//             create_tree(root->left,i,preorder[i],max,preorder);
//         }
//         if(preorder[i]>max){
//             root->right=new TreeNode(preorder[i]);
//             i++;
//             create_tree(root->right,i,min,preorder[i],preorder);
//         }
//     }
// public:
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         if(!preorder.size()) return NULL;
//         TreeNode* head=new TreeNode (preorder[0]);
//         create_tree(head,1,preorder[0],preorder[0],preorder);
//         return head;
//     }
// };