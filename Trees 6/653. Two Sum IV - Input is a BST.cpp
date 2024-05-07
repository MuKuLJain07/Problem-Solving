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
    void inOrder(TreeNode* root, vector<int> &trav){
        if(root == NULL){
            return;
        }
        inOrder(root->left, trav);
        trav.push_back(root->val);
        inOrder(root->right, trav);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL){
            return 0;
        }
        vector<int> trav;
        inOrder(root,trav);

        int i = 0;
        int j = trav.size() - 1;
        while(j > i){
            if(trav[i] + trav[j] == k){
                return true;
            }
            if(trav[i] + trav[j] > k){
                j-=1;
            }
            if(trav[i] + trav[j] < k){
                i+=1;
            }
        }
        return false;
    }
};