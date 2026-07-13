class Solution {
   public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> current;
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
        current.push_back(nums[i]);
        backtrack(current, nums, target - nums[i], i);
        current.pop_back();
        backtrack(current, nums, target, i + 1);
    }
};
