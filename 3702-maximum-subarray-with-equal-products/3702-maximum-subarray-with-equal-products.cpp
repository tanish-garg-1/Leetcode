class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans=2;
        for(int i=0;i<nums.size();i++){
            int l=nums[i];int g=nums[i];int prod=nums[i];
            for(int j=i+1;j<nums.size();j++){
                l=lcm(l,nums[j]);
                g=gcd(g,nums[j]);
                prod=prod*nums[j];
                if(prod!=l*g) break;
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};