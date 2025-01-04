class Solution {
    void function(int n,vector<int>& nums,vector<vector<int>>& sol,unordered_map<int,int> mymap,vector<int>& temp){
        if(temp.size()==n){
            sol.push_back(temp);
            return;
        }
        for(auto it=mymap.begin();it != mymap.end();it++){
            if(it->second==0) continue;
                temp.push_back(it->first);
                it->second=0;
                function(n,nums,sol,mymap,temp);
                it->second=1;
                temp.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        unordered_map<int,int> mymap;
        for(int i=0;i<nums.size();i++){
            mymap[nums[i]]=1;
        }
        vector<int> temp;
        function(nums.size(),nums,sol,mymap,temp);
        return sol;
    }
};