class Solution{
  public:
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;
        
        // base case
        if(root == NULL){
            return ans;
        }
            
        // vertical order traversal
        queue<pair<Node*, pair<int, int>>> q;
        map<int, int> mp;
        
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<Node*, pair<int, int>> temp = q.front();
            q.pop();
            
            Node* treeNode = temp.first;
            int hd = temp.second.first;
            int lv = temp.second.second;
            

            mp[hd] = treeNode->data;

            
            if(treeNode->left){
                q.push(make_pair(treeNode->left,make_pair(hd-1, lv+1)));
            }
            if(treeNode->right){
                q.push(make_pair(treeNode->right,make_pair(hd+1, lv+1)));
            }
        }
        
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
