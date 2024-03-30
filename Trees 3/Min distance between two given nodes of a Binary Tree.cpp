class Solution{
    private:
    Node* findLCA(Node* root, int a, int b){
        if(root == NULL){
            return NULL;
        }    
        if(root->data == a || root->data == b){
            return root;
        }
        
        Node* left = findLCA(root->left,a,b);
        Node* right = findLCA(root->right,a,b);
        if(left!=NULL && right!=NULL){
            return root;
        }
        else if(left!=NULL && right == NULL){
            return left;
        }
        else if(left == NULL && right != NULL){
            return right;
        }
        else{
            return NULL;
        }
    }
    
    int distFromLCA(Node* root, int x, int dist){
        // if x is not present in the tree
        if(root == NULL){
            return -1;
        }
        
        if(root->data == x){
            return dist;
        }
        
        int left = distFromLCA(root->left,x,dist+1);
        if(left != -1){
            return left;
        }
        return distFromLCA(root->right, x, dist+1);
    }
    
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        Node* LCA = findLCA(root,a,b);
        // cout<<LCA->data<<endl;
        
        int LCA_to_A_dist = distFromLCA(LCA,a,0);
        int LCA_to_B_dist = distFromLCA(LCA,b,0);
        
        return LCA_to_A_dist + LCA_to_B_dist;
    }
};