class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
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
            
            if(mp.find(hd) == mp.end()){
                mp[hd] = treeNode->data;
            }
            
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