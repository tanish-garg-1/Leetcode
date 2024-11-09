class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int sizee=matrix.size();
        int arr[sizee][sizee];
        for(int i=0;i<sizee;i++){
            for(int j=0;j<sizee;j++){
                arr[i][j]=matrix[i][j];
            }
        }
        for(int i=0;i<sizee;i++){
            for(int j=0;j<sizee;j++){
                matrix[i][j]=arr[sizee-1-j][i];
            }
        }
    }
};