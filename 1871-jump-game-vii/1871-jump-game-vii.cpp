class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        vector<int> reachable(n, 0);
        reachable[0] = 1;

        int count = 0;

        for (int i = 1; i < n; i++) {

            // add new index entering window
            if (i - minJump >= 0) {
                count += reachable[i - minJump];
            }

            // remove index leaving window
            if (i - maxJump - 1 >= 0) {
                count -= reachable[i - maxJump - 1];
            }

            // if there exists a reachable index in range
            // and current position is '0'
            if (count > 0 && s[i] == '0') {
                reachable[i] = 1;
            }
        }

        return reachable[n - 1];
    }
};