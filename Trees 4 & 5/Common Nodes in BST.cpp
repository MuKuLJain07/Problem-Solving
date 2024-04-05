// class Solution
// {
//     public:
//     //Function to find the nodes that are common in both BST. 
//     vector <int> findCommon(Node *root1, Node *root2)
//     {
//         vector<int> ans;
//         if(root1 == NULL || root2 == NULL){
//             return ans;
//         }
        
//         queue<Node*> q;
//         q.push(root1);
        
//         while(!q.empty()){
//             Node* temp = q.front();
//             q.pop();
            
//             Node* ptr = root2;
//             while(ptr!= NULL){
//                 if(ptr->data == temp->data){
//                     ans.push_back(ptr->data);
//                     break;
//                 }
//                 else if(ptr->data > temp->data){
//                     ptr = ptr->left;
//                 }
//                 else{
//                     ptr = ptr->right;
//                 }
//             }
            
//             if(temp->left){
//                 q.push(temp->left);
//             }
//             if(temp->right){
//                 q.push(temp->right);
//             }
//         }
//         sort(ans.begin(), ans.end());
//         return ans;
        
//     }
// };

class Solution
{
    private:
    void inorderTraversal(Node *root, unordered_map<int, int> &mp, vector<int> &ans){
        if(root == NULL){
            return;
        }
        inorderTraversal(root->left,mp,ans);
        if(mp.find(root->data) == mp.end()){
            mp[root->data] = 1;
        }
        else{
            ans.push_back(root->data);
        }
        inorderTraversal(root->right,mp,ans);
    }
    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        inorderTraversal(root1, mp, ans);
        inorderTraversal(root2, mp, ans);
        
        return ans;
    }
};