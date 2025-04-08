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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*>s1,s2;
        vector<vector<int>> sol;
        if(root==NULL) return sol;
        s1.push(root);
        while(s1.empty()==false || s2.empty()==false){

            vector<int> temp;
            while(s1.empty()==false){
                TreeNode* data=s1.top();
                s1.pop();
                temp.push_back(data->val);
                if(data->left) s2.push(data->left);
                if(data->right) s2.push(data->right);
            }
            if(temp.empty()==false) sol.push_back(temp);

            vector<int> temp1;
            while(s2.empty()==false){
                TreeNode* data=s2.top();
                s2.pop();
                temp1.push_back(data->val);
                if(data->right) s1.push(data->right);
                if(data->left) s1.push(data->left);
            }
            if(temp1.empty()==false) sol.push_back(temp1);
        }
        return sol;
    }
};