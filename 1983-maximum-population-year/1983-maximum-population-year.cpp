class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> mymap;
        for(int i=0;i<logs.size();i++){
            mymap[logs[i][0]]++;
            mymap[logs[i][1]]--;
        }
        vector<pair<int,int>> sol;
        for(auto it=mymap.begin();it!=mymap.end();it++){
            sol.push_back(make_pair(it->first,it->second));
        }
        sort(sol.begin(),sol.end());
        int year=(sol[0]).first;
        int ans=(sol[0]).second;
        for(int i=1;i<sol.size();i++){
            (sol[i]).second=(sol[i]).second+(sol[i-1]).second;
            if(ans<(sol[i-1]).second){
                ans=(sol[i-1]).second;
                year=(sol[i-1]).first;
            }
        }
        return year;
    }
};