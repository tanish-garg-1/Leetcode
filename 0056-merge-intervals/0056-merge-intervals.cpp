class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> vec;
        int sizee=intervals.size();
        std::sort(intervals.begin(), intervals.end());
        int y;
        for(int i=0;i<sizee;i++){
            int x=intervals[i][0];
            y=intervals[i][1];

            while(i<sizee-1 && y>=intervals[i+1][0]){
                i++;
                y=max(y,intervals[i][1]);
            }
            vec.push_back({x,y});
        }
        return vec;
    }
};