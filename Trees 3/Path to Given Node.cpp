/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool solveHelper(TreeNode* root, int B, vector<int> &path){
    if(root == NULL){
        return false;
    }
    
    path.push_back(root->val);
    if(root->val == B){
        return true;
    }
    
    if(solveHelper(root->left, B, path) || solveHelper(root->right, B, path)){
        return true;
    }
    path.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> path;
    solveHelper(A, B, path);
    return path;
}
