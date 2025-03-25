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
    bool isSame(TreeNode* node1, TreeNode* node2){
        if (node1 == NULL && node2 == NULL) return true;
        if (node1 == NULL || node2 == NULL) return false;
        return (node1->val == node2->val) && isSame(node1->left, node2->left) &&  isSame(node1->right, node2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == NULL) return true;
        if (root == NULL && subRoot != NULL) return false;
        if (isSame(root, subRoot)){
            return true;
        }
        if (isSubtree(root->left, subRoot) || (isSubtree(root->right, subRoot))){
            return true;
        }
        return false;
    }
};