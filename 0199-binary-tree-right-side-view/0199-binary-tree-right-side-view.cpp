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
    void right_view(TreeNode* root,unordered_map<int,int> &mymap,int level,vector<int>& sol){
        if(root==NULL) return;
        if(mymap.find(level) == mymap.end()){
            sol.push_back(root->val);
            mymap[level]++;
        }
        right_view(root->right,mymap,level+1,sol);
        right_view(root->left,mymap,level+1,sol);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        unordered_map<int,int> mymap;
        vector<int> sol;
        right_view(root,mymap,0,sol);
        return sol;
    }
};