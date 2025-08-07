class Solution {
    int find(vector<int>& nums, int k){
        unordered_map<int,int> mymap;
        int i=0,j=0,ans=0;
        int n=nums.size();
        while(j<n){
            mymap[nums[j]]++;
            j++;
            while(mymap.size()>k){
                mymap[nums[i]]--;
                if(mymap[nums[i]]==0) mymap.erase(nums[i]);
                i++;
            }
            ans=ans+j-i;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return(find(nums,k)-find(nums,k-1));
    }
};