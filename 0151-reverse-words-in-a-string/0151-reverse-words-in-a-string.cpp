class Solution {
public:
    string reverseWords(string s) {
        string neww;
        string temp;
        int i=s.size()-1;
        while(i>=0 && s[i]==' ')i--;

        for(int j=i;j>=0;j--){
            string x;
            while(j>=0 && s[j]!=' '){
                x.clear();
                x=x+s[j];
                temp=x+temp;
                j--;
            }
            neww=neww+temp+' ';
            temp.clear();
            bool worked=false;
            if(j>=0){
                while(j>=0 && s[j]==' ') j--;
                worked=true;
            }
            if(worked==true) j++;
        }
        if(neww.size()>0)neww.pop_back();
        return neww;
    }
};