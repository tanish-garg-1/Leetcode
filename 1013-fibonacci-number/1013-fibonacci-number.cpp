class Solution {
    int function(int n){
        if(n<=1) return n;
        return function(n-1)+function(n-2);
    }
public:
    int fib(int n) {
        int ans=function(n);
        return ans;
    }
};