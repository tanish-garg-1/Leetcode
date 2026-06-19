class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sol=0;
        int height=0;
        for(int i=0;i<gain.size();i++){
            height=height+gain[i];
            sol=max(height,sol);
        }
        return sol;
    }
};