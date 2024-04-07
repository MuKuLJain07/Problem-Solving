class TrieNode{
public:
    bool isTerminated;
    TrieNode* children[26];

    TrieNode() {
        this->isTerminated = false;
        for(int i = 0; i<26; i++){
            this->children[i] = NULL;
        }    
    }
};

class Trie {
private:
    void insertHelper(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminated = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* temp;
        if(root->children[index] != NULL){
            temp = root->children[index];
        }
        else{
            root->children[index] = new TrieNode();
            temp = root->children[index];
        }

        insertHelper(temp, word.substr(1));
    }

    bool searchHelper(TrieNode* root, string word){
        if(word.length() == 0){
            return root->isTerminated;
        }

        int index = word[0] - 'a';
        TrieNode* temp;
        if(root->children[index] != NULL){
            temp = root->children[index];
        }
        else{
            return false;
        }

        return searchHelper(temp, word.substr(1));
    }

    bool startsWithHelper(TrieNode* root, string word){
        if(word.length() == 0){
            return true;
        }

        int index = word[0] - 'a';
        TrieNode* temp;
        if(root->children[index] != NULL){
            temp = root->children[index];
        }
        else{
            return false;
        }

        return startsWithHelper(temp, word.substr(1));
    }
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        insertHelper(root, word);
    }
    
    bool search(string word) {
        return searchHelper(root,word);
    }
    
    bool startsWith(string prefix) {
        return startsWithHelper(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */