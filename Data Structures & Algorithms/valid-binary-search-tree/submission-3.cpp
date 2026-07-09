class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
    bool validate(TreeNode* node, long long min_val, long long max_val) {
        // Base case: An empty tree/node is valid
        if (!node) {
            return true;
        }

        // The current node's value must strictly fall within the min and max limits
        if (node->val <= min_val || node->val >= max_val) {
            return false;
        }

        // Left child must be smaller than the current node's value (updates max_val)
        // Right child must be larger than the current node's value (updates min_val)
        return validate(node->left, min_val, node->val) && 
               validate(node->right, node->val, max_val);
    }
};