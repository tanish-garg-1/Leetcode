class Solution {
    int find_index(int begin,int end,int target,vector<int>& nums){
        if(begin>end) return -1;
        int mid=(begin+end)/2;
        if(nums[mid]==target) return mid;

        if(nums[begin]<=nums[mid]){
            if(target>=nums[begin] && target<=nums[mid]){
                return find_index(begin,mid-1,target,nums);
            }
            else return find_index(mid+1,end,target,nums);
             
        }

        if(nums[mid+1]<=nums[end]){
            if(target>=nums[mid+1] && target<=nums[end]){
                return find_index(mid+1,end,target,nums);
            }
            else return find_index(begin,mid-1,target,nums);
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int begin=0,end=nums.size()-1;
        return find_index(begin,end,target,nums);
    }
};