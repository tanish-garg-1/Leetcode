class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m+n-1;i>=n;i--){
            nums1[i]=nums1[i-n];
        }
        for(int i=0;i<n;i++){
            nums1[i]=0;
        }
        for(int i=0;i<n+m;i++) cout<<nums1[i]<<" ";

        int i=n,j=0;
        int x=0;
        while(x<m+n && i<m+n && j<n){
            if(nums1[i]<=nums2[j]){
                nums1[x]=nums1[i];
                i++;x++;
            }
            else{
                nums1[x]=nums2[j];
                j++;x++;
            }
        }
        while(i==m+n && x<m+n){
            nums1[x]=nums2[j];
                j++;x++;
        }
        while(j==n && x<m+n){
            nums1[x]=nums1[i];
                i++;x++;
        }
    }
};