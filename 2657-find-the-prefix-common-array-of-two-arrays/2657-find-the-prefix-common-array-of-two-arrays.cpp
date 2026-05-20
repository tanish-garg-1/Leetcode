class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        unordered_map<int,int> mapa,mapb;
        vector<int> sol(a.size(),0);

        for(int i=0;i<a.size();i++){
            mapa[a[i]]++;mapb[b[i]]++;
            if(mapa.find(b[i]) != mapa.end()) sol[i]++;
            if(mapb.find(a[i]) != mapb.end()) sol[i]++;
            if(a[i]==b[i]) sol[i]--;
            if(i!=0){
                sol[i]=sol[i]+sol[i-1];
            }
        }

        return sol;
    }
};