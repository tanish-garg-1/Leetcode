class Solution {
    bool function(int start,int end,int target,vector<vector<int>>& matrix){
        if (start > end) return false;
        int mid=(start+end)/2;
        int i=mid/matrix[0].size();
        int j=mid%matrix[0].size();
        if(target==matrix[i][j]) return true;
        else if(target<matrix[i][j]){
            return function(start,mid-1,target,matrix);
        }
        else return function(mid+1,end,target,matrix);
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start=0;
        int end=matrix.size() * matrix[0].size()-1;
        bool ans=function(start,end,target,matrix);
        return ans;
    }
};