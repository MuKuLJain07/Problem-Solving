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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }

        // level order traversal while maintaining node, hd, lv
        map<int, map<int, vector<int> > > nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push(make_pair(root, make_pair(0,0)));

        while(!q.empty()){
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();

            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lv = temp.second.second;

            nodes[hd][lv].push_back(frontNode->val);

            if(frontNode->left){
                q.push(make_pair(frontNode->left, make_pair(hd-1, lv+1)));
            }
            if(frontNode->right){
               q.push(make_pair(frontNode->right, make_pair(hd+1, lv+1)));
            }
        }

        for(auto i: nodes){
            vector <int> small;
            for(auto j: i.second){
                for(auto k:j.second){
                    small.push_back(k);
                }
            }
            sort(small.begin(), small.end());
            ans.push_back(small);
        }

        return ans;
    }
};
