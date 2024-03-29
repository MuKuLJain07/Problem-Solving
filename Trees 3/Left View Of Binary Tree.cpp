vector<int> printLeftView(BinaryTreeNode<int>* root) {
    vector <int> ans;

    if(root == NULL){
        return ans;
    }

    queue <pair<BinaryTreeNode<int>*, int>> q;
    map<int, int> mp;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<BinaryTreeNode<int>*, int> temp = q.front();
        q.pop();

        BinaryTreeNode<int>* treeNode = temp.first;
        int lv = temp.second;

        if(mp.find(lv) == mp.end()){
            mp[lv] = treeNode->data;
        }

        if(treeNode->left){
            q.push(make_pair(treeNode->left, lv+1));
        }
        if(treeNode->right){
            q.push(make_pair(treeNode->right, lv+1));
        }
    }

    for(auto x: mp){
        ans.push_back(x.second);
    }
    return ans;
}