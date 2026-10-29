110. Balanced Binary Tree
Solved
Easy
Topics
premium lock icon
Companies
Given a binary tree, determine if it is height-balanced.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104


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
private:
    int  isbalance(TreeNode* root){
        if(root == NULL) return 0;
        int left=isbalance(root->left);
        if(left == -1) return -1;

        int right=isbalance(root->right);
        if(right == -1) return -1;

        if(abs(left-right) > 1) return -1;

        return 1+ max(left,right);
    }
public:
    bool isBalanced(TreeNode* root) {
    
        return isbalance(root) !=-1;
    }
};