class Solution {
public:
    int minElement(vector<int>& nums) {
        int minn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            int temp=nums[i];
            while(temp>=1){
                sum=sum+temp%10;
                temp=temp/10;
            }
            minn=min(sum,minn);
        }
        return minn;
    }
};