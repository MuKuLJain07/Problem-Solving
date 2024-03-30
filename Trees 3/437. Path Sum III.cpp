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
    void pathSumHelper(TreeNode* root, int targetSum, vector<int> path, int &count){
        if(root == NULL){
            return;
        }
        path.push_back(root->val);

        pathSumHelper(root->left,targetSum, path, count);
        pathSumHelper(root->right,targetSum, path, count);

        long long sum = 0;
        for(int i = path.size()-1; i>=0; i--){
            sum+=path[i];
            if(sum == targetSum){
                count+=1;
            }
        }

        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        vector <int> path;
        pathSumHelper(root,targetSum, path, count);
        return count;
    }
};