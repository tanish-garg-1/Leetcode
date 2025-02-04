class Solution {
    int find_val(char x){
          if(x=='I')  return 1;
            else if(x=='V') return 5;
            else if(x=='X') return 10;
            else if(x=='L') return 50;
            else if(x=='C') return 100;
            else if(x=='D') return 500;
            else return 1000;
    }
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