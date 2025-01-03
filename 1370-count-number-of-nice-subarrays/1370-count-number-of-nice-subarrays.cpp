class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }
        unordered_map<int,int> mymap;
        mymap[0]++;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(i!=0) nums[i]=nums[i]+nums[i-1];
            if(mymap.find(nums[i]-k)!=mymap.end()){
                ans=ans+mymap[nums[i]-k];
            }
            mymap[nums[i]]++;
        }
        return ans;
    }
};