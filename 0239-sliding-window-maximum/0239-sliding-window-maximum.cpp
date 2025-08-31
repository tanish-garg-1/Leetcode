class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        vector<int> sol;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while (!dq.empty() && dq.front().second <= i - k) dq.pop_front();

            while (!dq.empty() && dq.back().first <= nums[i]) dq.pop_back();

            dq.push_back({nums[i], i});
            if (i >= k - 1) sol.push_back(dq.front().first);
        }
        return sol;
    }
};