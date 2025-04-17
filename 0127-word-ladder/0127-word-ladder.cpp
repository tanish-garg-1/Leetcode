class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        while(!q.empty()){
            string s=(q.front()).first;
            int n=(q.front()).second;
            q.pop();
            if(s==endWord) return n;
            for(int i=0;i<beginWord.size();i++){
                string temp=s;
                for(char j='a';j<='z';j++){
                    temp[i]= j;
                    if(st.find(temp) != st.end()){
                        st.erase(temp);
                        q.push({temp,n+1});
                    }
                }
            }
        }
        return 0;
    }
};