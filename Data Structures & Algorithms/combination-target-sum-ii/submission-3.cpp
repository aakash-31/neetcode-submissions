class Solution {
   public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> current;
        sort(nums.begin(), nums.end());
        backtrack(current, nums, target, 0);
        return res;
    }
    void backtrack(vector<int>& current, vector<int>& nums, int target, int i) {
        if (target == 0) {
            res.push_back(current);
            return;
        }

        if (target < 0 || i >= nums.size()) {
            return;
        }
        for (int idx = i; idx < nums.size(); idx++) {
            if (idx>i && nums[idx] == nums[idx - 1]) {
                continue;}
            current.push_back(nums[idx]);
            backtrack(current, nums, target - nums[idx], idx+1);
            current.pop_back();
            // backtrack(current, nums, target, i + 1);
        }
    }
};
