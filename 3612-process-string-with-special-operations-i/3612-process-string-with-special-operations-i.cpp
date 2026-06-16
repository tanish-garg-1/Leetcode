class Solution {
    string reverse(string sol){
        for(int i=0;i<sol.size()/2;i++){
            swap(sol[i],sol[sol.size()-i-1]);
        }
        return sol;
    }
public:
    string processStr(string s) {
        string sol;
        for(int i=0;i<s.size();i++){
            char temp=s[i];
            if(temp=='#'){
                sol=sol+sol;
            }
            else if(temp=='*'){
                if(!sol.empty()) sol.pop_back();
            }
            else if(temp=='%'){
                sol=reverse(sol);
            }
            else sol=sol+temp;
        }
        return sol;
    }
};