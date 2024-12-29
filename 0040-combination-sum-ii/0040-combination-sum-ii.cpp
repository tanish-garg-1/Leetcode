class Solution {
    void function(int index,int sum,int target,vector<int>& candidates,vector<int>& temp,vector<vector<int>>& sol){
            if(sum==target){
                sol.push_back(temp);
                return;
            }

            for(int i=index;i<candidates.size();i++){
                if(i>index && candidates[i]==candidates[i-1]) continue;
                if (sum + candidates[i] > target) break;
                    temp.push_back(candidates[i]);
                    function(i+1,sum+candidates[i],target,candidates,temp,sol);
                    temp.pop_back();
            }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> sol;
        vector<int> temp;
        function(0,0,target,candidates,temp,sol);
        return sol;
    }
};