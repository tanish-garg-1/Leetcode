class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return true;
        int change=0;
        if(nums[0]<nums[n-1]) change++;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) change++;
            if(change>1) return false;
        }
        return true;
    }
};