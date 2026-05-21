class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s;
        int sol=0;
        for(int i=0;i<arr1.size();i++){
            int temp=arr1[i];
            while(temp>=1){
                s.insert(temp);
                temp=temp/10;
            }
        }

        for(int i=0;i<arr2.size();i++){
            int temp=arr2[i];
            int lcp=to_string(temp).length();
            while(temp>=1){
                if(s.find(temp) != s.end()){
                    sol=max(sol,lcp);
                }
                temp=temp/10;
                lcp--;
            }           
        }

        return sol;
    }
};