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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        if(root==NULL){
            return ans;
        }

        // creating queue for lv order traversal
        queue <TreeNode*> q;   // lv, Node ptr
        q.push(root);
        q.push(NULL);
        int currLv = 0;
        int currVal = root->val;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp){
                currVal = temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            else{
                ans.push_back(currVal);
                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }
        return ans;
    }
};