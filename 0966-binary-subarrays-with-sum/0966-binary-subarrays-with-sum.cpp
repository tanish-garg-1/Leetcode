class Solution {
    int equals_goal(vector<int>& nums, int goal){
        if(goal<0)return 0;
        int i=0,j=0,ans=0;
        
        while(j<nums.size()){
            goal=goal-nums[j];
            j++;
            while(goal<0){
                goal=goal+nums[i];
                i++;
            }
            ans=ans+j-i;
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return(equals_goal(nums,goal)-equals_goal(nums,goal-1));

    }
};