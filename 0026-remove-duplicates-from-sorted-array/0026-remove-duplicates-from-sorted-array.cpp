class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            while(i<nums.size() && temp==nums[i]) i++;
            if(i<nums.size() && temp!=nums[i]) i--;
            nums[count]=temp;
            count++;
        }
        return count;
    }
};