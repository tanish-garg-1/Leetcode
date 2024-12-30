class Solution {
    double calc_factorial(int a){
        double ans=1;
        for(double i=2;i<=a;i++){
            ans=ans*i;
        }
        return ans;
    }
public:
    string getPermutation(int n, int k) {
        double temp= static_cast<double>(k);
        vector<int> nums;
        string sol="";
        for(int i=1;i<=n;i++) nums.push_back(i);
        while(n>0){
            double fact=calc_factorial(n-1);
            int index = (int)((temp - 1) / fact); 
            sol=sol+to_string(nums[index]);
            nums.erase(nums.begin()+index);
            temp=temp-fact*index;
            n--;
        }
        return sol;
    }
};