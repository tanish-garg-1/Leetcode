class Solution {
    void function(int index,int sum,int target,vector<int>& candidates,vector<int>& temp,vector<vector<int>>& sol){
        if(index==candidates.size()){
            if(sum==target){
                sol.push_back(temp);
            }
            return;
        }
        if(sum<=target){
            temp.push_back(candidates[index]);
            function(index,sum+candidates[index],target,candidates,temp,sol);
            temp.pop_back();
        }
        function(index+1,sum,target,candidates,temp,sol);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        vector<int> temp;
        function(0,0,target,candidates,temp,sol);
        return sol;
    }
};