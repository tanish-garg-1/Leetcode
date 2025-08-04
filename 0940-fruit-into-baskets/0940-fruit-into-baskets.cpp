class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int ans=0;
        unordered_map<int,int> mymap;
        while(j<fruits.size()){
            mymap[fruits[j]]++;
            j++;

            while(mymap.size()>2){
                mymap[fruits[i]]--;
                if (mymap[fruits[i]] == 0) mymap.erase(fruits[i]);
                i++;
            }
            int sizee=0;
            for(auto it=mymap.begin();it!=mymap.end();it++){
                sizee=sizee+it->second;
            }
            ans=max(ans,sizee);
        }
        return ans;
    }
};