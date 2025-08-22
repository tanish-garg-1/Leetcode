class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mymap;
        for(int i=0;i<nums.size();i++){
            mymap[nums[i]]++;
        }

        priority_queue<pair<int,int>> pq;
        for(auto it=mymap.begin();it!=mymap.end();it++){
            pq.push({it->second,it->first});
        }
        
        vector<int> sol;
        while(k-- && !pq.empty()){
            auto it=pq.top();
            sol.push_back(it.second);
            pq.pop();
        }
        return sol;
    }
};