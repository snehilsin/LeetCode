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
    int getH(TreeNode* root){
        if (root == NULL) return 0;
        int leftH = getH(root->left);
        int rightH = getH(root->right);
        return 1 + max(leftH, rightH);
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int leftH = getH(root->left);
        int rightH = getH(root->right);
        if (abs(leftH - rightH) <=1 && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }
        return false;
    }
};