class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sizee=nums.size();
        int i=0;
        int sum=0;
        bool yes0=false;
        bool thisrun=false;
        int maxx=INT_MIN;
        while(i!=sizee){
            if(nums[i]==0) yes0=true;
            sum=sum+nums[i];
            if(sum<0) {sum=0;thisrun=true;}
            maxx=max(maxx,nums[i]);
            maxx=max(sum,maxx);
            i++;
        }
        if(yes0==false && thisrun==true && sum==0 && maxx==0) 
        return *max_element(nums.begin(), nums.end());
        return max(maxx,sum);
    }
};