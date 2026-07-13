class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>sub;
        result(nums,0,sub,res);
        return res;
        
    }
    void result(vector<int>&nums,int i,vector<int>&sub, vector<vector<int>>&res){
        if(i>=nums.size()){
            res.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        result(nums,i+1,sub,res);
        sub.pop_back();
        result(nums,i+1,sub,res);
    }

};
