class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0;
        int ans=0;
        unordered_map<char,int> mymap;
        while(j<s.size()){
            mymap[s[j]]++;
            j++;
            while(i<j && mymap.size()>=3) {
                ans=ans+s.size()-j+1;
                mymap[s[i]]--;
                if(mymap[s[i]]==0) mymap.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};