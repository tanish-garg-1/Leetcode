class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        while(nums[i]!=0){
            int temp=nums[i];
            nums[i]=0;
            i=temp;
        }
        return i;
    }
};