class Solution {
    bool decide=false;
    void function(int index,vector<int>& temp,vector<int>& nums,vector<vector<int>>& sol){
        sol.push_back(temp);
        for(int i=index;i<nums.size();++i){
            if (i > index && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            function(i+1,temp,nums,sol);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        int sizee=nums.size();
        vector<int> temp;
        function(0,temp,nums,sol);
        return sol;
    }
};