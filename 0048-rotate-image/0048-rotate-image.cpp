class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int sizee=matrix.size();
        for(int i=0;i<sizee-1;i++){
            for(int j=i+1;j<sizee;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<sizee;i++){
            for(int j=0;j<sizee/2;j++){
                swap(matrix[i][j],matrix[i][sizee-1-j]);
            }
        }
    }
};