class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0;
        int ans=0;
        int maxx=0;
        map<char,int> mymap;
        while(j<s.size()){

            mymap[s[j]]++;
            if(mymap[s[j]]>maxx) maxx= mymap[s[j]];
            j++;
            

            while(k<j-i-maxx && i<s.size()){
                mymap[s[i]]--;
                i++;
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};