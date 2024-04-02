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
// class Solution {
// private:
//     bool isValidBSTHelper(TreeNode* root, int mini, int maxi){
//         if(root == NULL){
//             return true;
//         }
//         if(root->val > mini && root->val < maxi){
//             bool leftAns = isValidBSTHelper(root->left, mini, root->val);
//             bool rightAns = isValidBSTHelper(root->right, root->val, maxi);
//             return leftAns && rightAns;
//         }
//         return false;
//     }
// public:
//     bool isValidBST(TreeNode* root) {
//         return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
//     }
// };


class Solution {
    bool validateBst(TreeNode* root, long min, long max) {
        if (root == NULL)
            return true;

        if (root->val <= min || root->val >= max)
            return false;

        return validateBst(root->left, min, root->val) &&
               validateBst(root->right, root->val, max);
    }

public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        return validateBst(root, LONG_MIN, LONG_MAX);
    }
};