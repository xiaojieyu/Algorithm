/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    int distributeCoins(TreeNode* root) {
        sum = 0;
        moveCoins(root);
        return sum;
    }
    
    int moveCoins(TreeNode* root) {
        int left = 0, right = 0;
        if (root->left == nullptr && root->right == nullptr) {
            sum += abs(root->val - 1);
            return root->val - 1;
        }
        
        if (root->left != nullptr) {
            left = moveCoins(root->left);
        }
        if (root->right != nullptr) {
            right = moveCoins(root->right);
        }
        sum += abs(left + right + root->val - 1);
        return left + right + root->val - 1;
    }
};
