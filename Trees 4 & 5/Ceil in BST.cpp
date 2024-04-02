int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    int ans = -1;
    Node* temp = root;
    while(temp != NULL){
        if(temp->data == input){
            return input;
        }
        else if(temp->data > input){
            ans = temp->data;
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return ans;
}