class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> arr(nums2.size(),-1);
        int i=nums2.size();
        while(i--){
            // if(s.empty()){
            //     continue;
            // }
            // else{
                while(!s.empty() && nums2[i]>=s.top()) s.pop();
                if(!s.empty()) arr[i]=s.top();
            // }
            s.push(nums2[i]);
        }

        unordered_map<int,int> mymap;
        for(int i=0;i<nums2.size();i++){
            mymap[nums2[i]]=arr[i];
        }

        vector<int> sol;
        for(int i=0;i<nums1.size();i++){
            sol.push_back(mymap[nums1[i]]);
        }
        return sol;
    }
};