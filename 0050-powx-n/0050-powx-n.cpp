class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 || x==1 || (x==-1 && n%2==0))  return 1;
        if(x==-1 && n%2==1) return -1;
        if(n>0){
            double ans=1;
            while(n>1){
                ans=ans*x*x;
                n=n-2;
            }
            if(n==1) ans=ans*x;
            return ans;
        }
        else{
            double ans=1;
           while(n<-1){
                ans=ans*(1/x)*(1/x);
                n=n+2;
                if(ans<0.000001&& ans>-0.000001) return 0;
            } 
            if(n==-1) ans=ans*(1/x);
            return ans;
        }
    }
};