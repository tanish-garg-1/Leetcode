class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> mymap;
        mymap[0]=-1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) nums[i]=-1;
            if(i!=0){
                nums[i]=nums[i]+nums[i-1];
            }
            if(mymap.find(nums[i]) != mymap.end()){
                ans=max(ans,i-mymap[nums[i]]);
            }
            else{
                mymap[nums[i]]=i;
            }
        }
        return ans;
    }
};