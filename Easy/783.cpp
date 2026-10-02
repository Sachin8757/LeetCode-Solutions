Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

 

Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 105


class Solution {
private:
    void solve(TreeNode* root,vector<int>&nums){
        if(!root) return;
        solve(root->left,nums);
        nums.push_back(root->val);
        solve(root->right,nums);
    }
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> nums;

        solve(root, nums);

        int mdif = INT_MAX;

        for (int i = 1; i < nums.size(); i++) {
            mdif = min(mdif, nums[i] - nums[i - 1]);
        }

        return mdif;
    }
};


class Solution {
public:
    TreeNode* prev = NULL;
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;

        if(root == NULL)
            return INT_MAX;

        if(root -> left) {
            int leftMin = minDiffInBST(root -> left);
            ans = min(ans, leftMin);
        }

        if(prev) 
            ans = min(ans, root -> val - prev -> val);

        prev = root;

        if(root -> right) {
            int rightMin = minDiffInBST(root -> right);
            ans = min(ans, rightMin);
        }

        return ans;
    }
};