class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> my_map;
        for(int i=0;i<nums.size();i++){
            my_map[nums[i]]=i;
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(my_map.find(target-nums[i])!=my_map.end()  && i!=my_map[target-nums[i]]){
                ans.push_back(i);
                ans.push_back(my_map[target-nums[i]]);
                break;
            }
        }
        return ans;
    }
};