class Solution {
    void function(int k,vector<int>& nums,vector<vector<int>> &sol){
        if (k == nums.size()) {
            sol.push_back(nums); 
            return;
        }
        for(int i=k;i<nums.size();i++){
            swap(nums[i], nums[k]);
            function(k+1,nums,sol);
            swap(nums[i],nums[k]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        function(0,nums,sol);
        return sol;
    }
};