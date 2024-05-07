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
    TreeNode* insertIntoBST(TreeNode* root, int val){
        if(root == NULL){
            root = new TreeNode(val);
            return root;
        }
        if(root->val > val){
            root->left = insertIntoBST(root->left,val);
        }
        else if(root->val < val){
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() <= 0){
            return NULL;
        }
        TreeNode* root = NULL;
        for(int i = 0; i < preorder.size(); i++){
            root = insertIntoBST(root,preorder[i]);
        }
        return root;
    }
};

