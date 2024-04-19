class TrieNode{
    public:
    TrieNode* children[26];
    int index;
    int len;

    TrieNode(){
        for(int i = 0; i < 26; i++){
            this->children[i] = NULL;
        }
        this->len = 0;
        this->index = -1;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }

    void insert(string word, int index){
        TrieNode* temp = root;
        int length = word.length();
        for(int i = length-1 ; i>=0; i--){
            int in = word[i] - 'a';
            if(temp->children[in] == NULL){
                temp->children[in] = new TrieNode();
                temp->children[in]->len = length;
                temp->children[in]->index = index;
            }
            else{
                if(temp->children[in]->len > length){
                    temp->children[in]->len = length;
                    temp->children[in]->index = index;
                }
            }
            temp = temp->children[in];
        }
    }
    int query(string query, int &index){
        TrieNode* temp = root;
        for(int i = query.length()-1; i>=0; i--){
            int in = query[i] - 'a';
            if(temp->children[in] == NULL){
               return index; 
            }
            temp = temp->children[in];
            index = temp->index;
        }
        return index;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie* t = new Trie();
        for(int i = 0; i < wordsContainer.size(); i++){
            t->insert(wordsContainer[i],i);
        }

        int indexWithSmallestLen = -1;
        int lenWord = INT_MAX;
        for(int i = 0; i < wordsContainer.size(); i++){
            if(lenWord > wordsContainer[i].size()){
                lenWord = wordsContainer[i].size();
                indexWithSmallestLen = i;
            }
        }
        vector<int> ans;
        for(auto q:wordsQuery){
            int index = indexWithSmallestLen;
            t->query(q,index);
            ans.push_back(index);
        }
        return ans;
    }
};