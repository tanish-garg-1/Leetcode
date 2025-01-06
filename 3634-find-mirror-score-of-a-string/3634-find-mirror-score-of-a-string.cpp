class Solution {
public:
    long long calculateScore(string s) {
        vector<vector<int>> letters(26);
        long long score=0;
        for(int i=0;i<s.size();i++){
            if(letters[122-int(s[i])].empty()==false){
                score += i-letters[122-int(s[i])].back();
                letters[122-int(s[i])].pop_back();
            }
            else{
                letters[int(s[i])-97].push_back(i);
            }
        }
        return score;
    }
};