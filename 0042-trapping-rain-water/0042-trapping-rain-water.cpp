class Solution {
public:
    int trap(vector<int>& height) {
        int count=0;
        if(height.size()<=2) return 0;
        for(int i=0;i<height.size();i++) count=count+height[i];
        int blocks=0,total=0,prev_max_height,max_height=0;
        int i=0,j=height.size()-1;
        while(height[i]==0)i++;
        while(height[j]==0)j--;
        while(i<=j){
            prev_max_height=max_height;
            max_height=max(max_height,min(height[i],height[j]));

            if(max_height>prev_max_height){
                total=total+(max_height-prev_max_height)*(j-i+1);
                if(height[i]<height[j]){
                    blocks=blocks+height[i];
                    i++;
                }
                else if(height[j]<height[i]){
                    blocks=blocks+height[j];
                    j--;
                }
                else{
                    blocks=blocks+height[i]+height[j];
                    i++;j--;
                }
            }
            if(i>j) break;
            while(i<=j && height[i]<=max_height){blocks=blocks+height[i];i++;}
            while(i<=j && height[j]<=max_height){blocks=blocks+height[j];j--;}
        }
        cout<<total<<" "<<blocks;
        return total-count;
    }
};