class Solution {
    int find(vector<int>& nums, int k){
        int i=0,j=0,ans=0;
        while(j<nums.size()){
            if(nums[j]%2==1) k--;
            j++;
            while(k<0){
                if(nums[i]%2==1) k++;
                i++;
            }
            ans += (j - i);
        }
        return ans;       
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (find(nums,k)-find(nums,k-1));
    }
};