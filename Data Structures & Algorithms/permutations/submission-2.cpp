class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(0, nums);
        return res;
    }

    void backtrack(int index, vector<int>& nums) {
        // Base case: if we've fixed all elements, record the permutation
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);       // Choose: swap current element to the front
            backtrack(index + 1, nums);       // Explore: move to the next position
            swap(nums[index], nums[i]);       // Un-choose: undo the swap (backtrack)
        }
    }
};