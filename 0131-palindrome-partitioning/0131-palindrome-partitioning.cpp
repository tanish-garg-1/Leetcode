class Solution {
    bool is_palindrome(string s,int begin,int end){
        while(begin<=end){
            if(s[begin++]!=s[end--]) return false;
        }
        return true;
    }
    void function(string s,vector<string> temp,vector<vector<string>>& sol,int begin){
        if(begin==s.size()) sol.push_back(temp);
        for(int i=begin;i<s.size();i++){
            if(is_palindrome(s,begin,i)){
                temp.push_back(s.substr(begin,i+1-begin));
                function(s,temp,sol,i+1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> sol;
        vector<string> temp;
        function(s,temp,sol,0);
        return sol;
    }
};