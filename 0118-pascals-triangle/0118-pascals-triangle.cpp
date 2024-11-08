class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> neww;
        int arr[numRows][numRows];
        arr[0][0]=1;
        int pointer=0;
        // For each row:
        neww.push_back(vector<int>());  // Add an empty vector to `neww`
        neww[pointer].push_back(1);     // Now it's safe to add `1` to the first row

        for(int i=1;i<numRows;i++){
            pointer++;
            neww.push_back(vector<int>());
            for(int j=0,x=i;j<=i,x>=0;j++,x--){
                int a,b;
                if(x-1<0 || j<0) a=0;
                else a=arr[x-1][j];
                if(x<0 || j-1<0) b=0;
                else b=arr[x][j-1];
                arr[x][j] = a + b;

                neww[pointer].push_back(arr[x][j]);
            }
        }
        return neww;
    }
};