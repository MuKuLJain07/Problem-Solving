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
    string convertToString(vector<int> &path){
        string p = "";
        for(int i = 0; i < path.size()-1; i++){
            p+=to_string(path[i]);
            p+="->";
        }
        p+=to_string(path[path.size()-1]);
        return p;
    }
    void solve(TreeNode* root, vector<int> &path, vector<string> &ans){
        if(root == NULL){
            return;
        }      
        if(root->left == NULL && root->right == NULL){
            path.push_back(root->val);
            string rootTOLeaf = convertToString(path);
            ans.push_back(rootTOLeaf);
            path.pop_back();
            return;
        }

        path.push_back(root->val);
        solve(root->left,path, ans);
        solve(root->right, path, ans);
        path.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> path;
        solve(root,path, ans);
        return ans;
    }
};