/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count=k;
        int val=-1;
        dfs(root,k,val);
        return val;
    }

    void dfs(TreeNode * node,int & count ,int & val){
        if(!node)
            return;
        dfs(node->left,count,val);
        count--;
        if(count==0){
            val=node->val;
            return;
        }

        dfs(node->right,count,val);
        
    }
};
