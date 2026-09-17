class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int area=0;
        while(l<r){
            area=max(area,(r-l)*(min(nums[l],nums[r])));
            if(nums[l]<nums[r])
                l++;
            else
                r--;
            
        }
        return area;

        
    }
};
