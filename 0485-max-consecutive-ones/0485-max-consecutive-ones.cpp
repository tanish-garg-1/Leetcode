class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            while(i<nums.size() && nums[i]==1){count++;i++;}
            ans=max(ans,count);
            count=0;
        }
        return ans;
    }
};