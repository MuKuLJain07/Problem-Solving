class TrieNode{
    public:
    TrieNode* child[2];

    TrieNode(){
        this->child[0] = NULL;
        this->child[1] = NULL;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }

    void insertIntoTrie(int num){
        TrieNode* temp = root;
        for(int i = 31; i >=0; i--){
            int currBit = (num>>i)&1;
            if(temp->child[currBit] == NULL){
                temp->child[currBit] = new TrieNode;
            }
            temp = temp->child[currBit];
        }
    }
    int max_xor(int num){
        TrieNode* curr = root;
        int ans = 0;
        for(int i = 31;i>=0; i--){
            int currBit = (num>>i)&1;
            if(curr->child[!currBit]){
               ans+=(1<<i); 
               curr = curr->child[!currBit];
            }
            else{
                curr = curr->child[currBit];
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        Trie* t = new Trie();

        for(int i=0; i<nums.size(); i++){
            t->insertIntoTrie(nums[i]);
        }
        for(int i=0; i<nums.size(); i++){
            ans = max(ans,t->max_xor(nums[i]));
        }
        return ans;
    }
};