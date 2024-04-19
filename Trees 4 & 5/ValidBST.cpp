// class Solution{
//     public:
//     bool isValidBSTHelper(Node* root, int mi, int ma){
//         if(root == NULL){
//             return true;
//         }
//         if(root->data >= ma || root->data <= mi){
//             return false;
//         }
    
//         return isValidBSTHelper(root->left,mi,root->data) && isValidBSTHelper(root->right,root->data,ma);
//     }
    
//     bool isValidBST(Node* root){
//         return isValidBSTHelper(root,INT_MIN,INT_MAX);
//     }
    
//     int sizeBST(Node* root){
//     if(root == NULL){
//         return 0;
//     }

//     int leftSize = sizeBST(root->left);
//     int rightSize = sizeBST(root->right);

//     return leftSize + rightSize + 1;
//     }
    
//     void largestBstHelper(Node *root, int &ans){
//         if(root == NULL){
//             return;
//         }
//         if(isValidBST(root)){
//             ans = max(ans, sizeBST(root));
//         }
//         largestBstHelper(root->left, ans);
//         largestBstHelper(root->right, ans); 
//     }
    
//     int largestBst(Node *root)
//     {
//         int sizeOFLargestBST = 1;
//         largestBstHelper(root, sizeOFLargestBST);
//         return sizeOFLargestBST;
        
//     }
// };


class Solution{
    public:
    class info{
        public:
            int maxi;
            int mini;
            bool isBST;
            int size;
    };
    
    info largestBstHelper(Node* root, int &ans){
        if(root == NULL){
            return {INT_MAX, INT_MIN, true, 0};
        }
        
        info left = largestBstHelper(root->left, ans);
        info right = largestBstHelper(root->right, ans);
        
        info curr;
        curr.size = left.size + right.size + 1;
        curr.maxi = max(root->data, right.maxi);
        curr.mini = min(root->data, left.mini);
        
        if(left.isBST && right.isBST && (root->data < curr.maxi && root->data > curr.mini)){
            curr.isBST = true;
        }
        else{
            curr.isBST = false;
        }
        
        if(curr.isBST){
            ans = max(ans,curr.size);
        }
        return curr;
    }
    
    int largestBst(Node *root)
    {
    	int ans = 1;
    	info temp = largestBstHelper(root,ans);
    	return ans;
    }
};