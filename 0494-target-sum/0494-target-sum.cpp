// class Solution {
//     int recursion(int i,int target,vector<int>& nums,vector<vector<int>>& dp){
//         if(target==0 && i<0) return 1;
//         if(i<0) return 0;
//         if(dp[i][target+10000] != -1) return dp[i][target+10000];
//         int left=recursion(i-1,target-nums[i],nums,dp);
//         int right=recursion(i-1,target+nums[i],nums,dp);
//         return dp[i][target+10000]=left+right;
//     }
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n=nums.size();
//         vector<vector<int>> dp(n,vector<int>(n*1000 +1,-1));
//         return recursion(n-1,target,nums,dp);
//     }
// };

class Solution {
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ hash<int>()(p.second << 1);
        }
    };

    int recursion(int i,int target,vector<int>& nums,unordered_map<pair<int,int>,int,pair_hash>& mymap){
        if(target==0 && i<0) return 1;
        if(i<0) return 0;
        pair<int, int> key={i,target};
        if(mymap.find(key) != mymap.end()) return mymap[key];
        // if(dp[i][target+10000] != -1) return dp[i][target+10000];
        int left=recursion(i-1,target-nums[i],nums,mymap);
        int right=recursion(i-1,target+nums[i],nums,mymap);
        return mymap[key]=left+right;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<pair<int,int>,int,pair_hash> mymap;
        return recursion(n-1,target,nums,mymap);
    }
};