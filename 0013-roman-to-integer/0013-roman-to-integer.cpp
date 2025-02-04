class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mymap;
        mymap['I']=1;
        mymap['V']=5;
        mymap['X']=10;
        mymap['L']=50;
        mymap['C']=100;
        mymap['D']=500;
        mymap['M']=1000;
        
        int ans=0;

        for(int i=s.size()-1;i>=0;i--){
            int temp=mymap[s[i]];
            while(i>0 && mymap[s[i]]>mymap[s[i-1]]){
                temp=temp-mymap[s[i-1]] ;
                i--;
                cout<<"entered wlile loop  ";
            }
            cout<<temp<<endl;
            ans=ans+temp;
        }
        return ans;
    }
};