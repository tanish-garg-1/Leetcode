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