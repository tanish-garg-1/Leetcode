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
    queue<TreeNode*> q;
    vector<vector<int>> v;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root!=NULL) q.push(root);
        while(q.empty()==false){
            int sizee=q.size();
            vector<int>temp;
            while(sizee--){
                TreeNode* var=q.front();
                temp.push_back(var->val);
                q.pop();
                if(var->left !=NULL)q.push(var->left);
                if(var->right !=NULL)q.push(var->right);
            }
            v.push_back(temp);
        }
        return v;
    }
};