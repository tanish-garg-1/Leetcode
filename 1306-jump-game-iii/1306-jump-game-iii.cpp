class Solution {
    bool jump(int i,vector<int>& arr, vector<bool>& visited){
        if(i<0 || i>=arr.size() || visited[i]==true) return false;
        visited[i]=true;
        if(arr[i]==0) return true;
        return jump(i+arr[i],arr,visited) || jump(i-arr[i],arr,visited);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> visited(n,false);
        return jump(start,arr,visited);
    }
};