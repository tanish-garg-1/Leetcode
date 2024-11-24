class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end(),greater<>());
        int i=0,j=nums.size()-1;
        vector<int>ans;
        while(i<j){
            if(arr[i].first+arr[j].first==target){
                ans.push_back(arr[i].second);ans.push_back(arr[j].second);
                break;
            }
            else if(arr[i].first+arr[j].first<target) j--;
            else i++;
        }
        return ans;
    }
};


/*
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
*/