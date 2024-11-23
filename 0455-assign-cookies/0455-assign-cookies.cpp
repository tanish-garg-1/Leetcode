class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0;
        int i=0,j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i!=g.size() && j!=s.size()){
            if(g[i]>s[j]) j++;
            else{
                count++;i++;j++;
            }
        }
        return count;
    }
};
