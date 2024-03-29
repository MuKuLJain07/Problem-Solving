class Solution{
  public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
       if(root == NULL){
           return 0;
       }
       
       bool CurrLvStatus = true;      // true is level is odd
       queue <Node*> q;
       q.push(root);
       q.push(NULL);
       
       int sumOdd = 0;
       int sumEven = 0;
       
       while(!q.empty()){
           Node* temp = q.front();
           q.pop();
           
           if(temp == NULL){
               if(!q.empty()){
                   q.push(NULL);
               }
               CurrLvStatus = !CurrLvStatus;
           }
           else{ 
               if(CurrLvStatus){
                  sumOdd += temp->data; 
               }
               else{
                   sumEven += temp->data;
               }
               if(temp->left){
                   q.push(temp->left);
               }
               if(temp->right){
                   q.push(temp->right);
               }
           }
       }
       
       return sumOdd - sumEven;
    }
};