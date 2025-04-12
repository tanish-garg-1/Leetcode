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

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        vector<int> sol;
        unordered_map<TreeNode*,TreeNode*> mymap;
        q.push(root);
        while(!q.empty()){
            int sizee=q.size();
            while(sizee--){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=NULL) {
                q.push(temp->left);
                mymap[temp->left]=temp;
                }
                if(temp->right!=NULL) 
                {mymap[temp->right]=temp;
                        q.push(temp->right);}
            }
        }

        unordered_map<TreeNode*,int> visited;
        q.push(target);
        int i=0;
        while(!q.empty()){
            int sizee=q.size();
            while(sizee--){
                TreeNode* temp=q.front();
                if(i==k) sol.push_back(temp->val);
                q.pop();
                visited[temp]++;
                if(temp->left!=NULL && visited.find(temp->left)==visited.end()) q.push(temp->left);
                if(temp->right!=NULL  && visited.find(temp->right)==visited.end()) q.push(temp->right);
                if(mymap.find(temp)!=mymap.end() && visited.find(mymap[temp])==visited.end()) q.push(mymap[temp]);
            }
            i++;
        }
        return sol;
    }
};