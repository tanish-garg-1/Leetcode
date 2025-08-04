// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int i=0;
//         queue<int> q;
//         int ans=0;
//         while(i<nums.size()){
//             while(k>=0 && i<nums.size()){
//                 if(k==0 && nums[i]==0) break;
//                 q.push(nums[i]);
//                 i++;
//             }
//             ans=max(ans,static_cast<int>(q.size()));
//             while(!q.empty() && q.front()==1) q.pop();
//             if(!q.empty()) q.pop();
//             k++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int ans=0;
        while(j<nums.size()){
            if(nums[j]==0) k--;
            j++;

            while(k<0){
                if(nums[i]==0) k++;
                i++;
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};