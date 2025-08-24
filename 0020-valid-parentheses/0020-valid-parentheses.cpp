class Solution {
    stack<char> s1;
public:
    bool isValid(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                s1.push(s[i]);
            }
            else{
                if(s1.empty()) return false;
                if(s[i]=='}' && s1.top()=='{') s1.pop();
                else if(s[i]==')' && s1.top()=='(') s1.pop();
                else if(s[i]==']' && s1.top()=='[') s1.pop();
                else return false;
            }
        }
        return s1.empty();
    }
};