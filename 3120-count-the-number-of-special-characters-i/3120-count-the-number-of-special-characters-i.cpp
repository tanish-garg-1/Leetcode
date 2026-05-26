class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> vals(52,0);
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            int ascii=static_cast<int>(ch);
            if(ascii>=65 && ascii<=90) vals[ascii-65]++;
            else vals[ascii-97+26]++;
        }
        int sol=0;
        for(int i=0;i<26;i++){
            if(vals[i]!=0 && vals[i+26]!=0) sol++;
        }      
        return sol;
    }
};