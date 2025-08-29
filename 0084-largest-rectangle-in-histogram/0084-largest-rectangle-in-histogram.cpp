class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left(n),right(n);
        stack<int> s;
        

        for(int i=0;i<n;i++){
            int temp=1;
            while(!s.empty() && heights[i]<=heights[s.top()]){
                s.pop();
                temp++;
            }
            left[i]=s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();
        for(int i=n-1;i>-1;i--){
            int temp=1;
            while(!s.empty() && heights[i]<=heights[s.top()]){
                s.pop();
                temp++;
            }
            right[i]=s.empty() ? n : s.top();
            s.push(i);            
        }

        int ans=0;
        for(int i=0;i<n;i++){
            int width=right[i]-left[i]-1;
            ans=max(ans,heights[i]*width);
        }
        return ans;
    }
};