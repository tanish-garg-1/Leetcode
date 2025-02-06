class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minn=INT_MAX;
        for(int i=0;i<strs.size();i++){
            minn=min(minn,(int)strs[i].size());
        }
        cout<<minn;
        string sol;
        for(int i=0;i<minn;i++){
            bool same=true;
            for(int j=0;j<strs.size();j++){
                if(strs[j][i] != strs[0][i]){
                    same =false;
                    break;
                }
            }
            if(same) sol=sol+strs[0][i];
            else break;
        }
        return sol;
    }
};