class Solution {
    void function(int i,vector<int> temp,vector<int>& nums,vector<vector<int>> &sol){
        if(i==nums.size()){ 
            sol.push_back(temp);
            return;
        }
        function(i+1,temp,nums,sol);
        temp.push_back(nums[i]);
        function(i+1,temp,nums,sol);
        temp.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> temp;
        function(0,temp,nums,sol);
        return sol;
    }
};