class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int sol=0;
        sort(costs.begin(),costs.end());
        for(int i=0;i<costs.size();i++){
            if(costs[i]<=coins){
                sol++;
                coins=coins-costs[i];
            }
        }
        return sol;
    }
};