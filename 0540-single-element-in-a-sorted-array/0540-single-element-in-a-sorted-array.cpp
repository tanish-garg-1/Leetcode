class Solution {
int function(vector<int>& nums,int low,int high){
    while(low<high){
        int mid=(low+high)/2;
        if(mid%2==0){
            if(nums[mid]==nums[mid+1]) return function(nums,mid+2,high);
            else return function(nums,low,mid);
        }
        else{
            if(nums[mid]!=nums[mid+1]) return function(nums,mid+1,high);
            else return function(nums,low,mid-1);
        }
    }
    return nums[low];
}
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int ans=function(nums,low,high);
        return ans;
    }
};