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

/**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int rangeSumBSTHelper(TreeNode* root, int low, int high, int add){
//         if(root==NULL){
//             return 0;
//         }
//         if(root->val>=low && root->val<=high){
//             add+=root->val;
//         }
//         add = rangeSumBSTHelper(root->left,low,high,add);
//         add = rangeSumBSTHelper(root->right,low,high,add);
//         return add;

//     }
//     int rangeSumBST(TreeNode* root, int low, int high) {
//         int result = 0;
//         // int ans = rangeSumBSTHelper(root,low,high,0);
//         if(root==NULL){
//             return NULL;
//         }
//         if(root->val>=low && root->val<=high){
//             result+=root->val;
//         }
//         result+=rangeSumBST(root->left,low,high);
//         result+=rangeSumBST(root->right,low,high);

//         return result;
        
//     }
// };


class Solution {
public:
    void rangeSumBSTHelper(TreeNode* root, int low, int high, int &ans){
        if(root == NULL){
            return;
        }
        if(root->val <= high && root->val >= low){
            ans+=root->val;
            rangeSumBSTHelper(root->left, low, high, ans);
            rangeSumBSTHelper(root->right, low, high, ans);
        }
        else if(root->val > high){
            rangeSumBSTHelper(root->left, low, high, ans);;
        }
        else{
            rangeSumBSTHelper(root->right, low, high, ans);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        rangeSumBSTHelper(root,low,high,ans);
        return ans;
    }
};