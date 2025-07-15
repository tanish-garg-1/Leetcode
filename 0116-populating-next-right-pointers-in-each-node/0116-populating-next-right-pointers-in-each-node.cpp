/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        Node* head=root;
        if(root!=NULL)q.push(root);
        else return head;
        while(!q.empty()){
            Node* parent=new Node();
            int s=q.size();
            while(s--){
                if(parent!=NULL) parent->next=q.front();
                parent=q.front();
                q.pop();
                if(parent->left != NULL)q.push(parent->left);
                if(parent->right != NULL)q.push(parent->right);
        
            }
            parent->next=NULL;
        }
        return head;
    }
};