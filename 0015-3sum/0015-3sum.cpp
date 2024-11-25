class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int k=0;k<nums.size()-2;k++){
            if (k > 0 && nums[k] == nums[k - 1]) continue;
           int i=k+1,j=nums.size()-1; 
           while(i<j){

            if(i<nums.size() && j<nums.size() && nums[i]+nums[j]+nums[k]==0){
                ans.push_back({nums[i],nums[j],nums[k]});
                i++;j--;

                while(i<nums.size() && nums[i]==nums[i-1]) i++;
                while(j+1<nums.size() && j>0 && nums[j]==nums[j+1]) j--;
            }

            else if(nums[i]+nums[j]+nums[k]>0) j--;
            else i++;
           }
        }  
        return ans;
    }
};