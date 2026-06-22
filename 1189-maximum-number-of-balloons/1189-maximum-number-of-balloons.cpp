class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> cnt;

        for(char c : text)
            cnt[c]++;

        return min({
            cnt['b'],
            cnt['a'],
            cnt['n'],
            cnt['l'] / 2,
            cnt['o'] / 2
        });
    }
};