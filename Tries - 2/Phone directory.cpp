class TrieNode{
    public:
    bool isTerminated;
    TrieNode* children[26];
    set<string> commonPrefixNames;

    TrieNode(){
        this->isTerminated = false;
        for(int i = 0; i < 26; i++){
            this->children[i] = NULL;
        }
    }
};

class Trie{
    private:
    // insert the given word into the Trie
    void insertIntoTrieHelper(TrieNode* root, string word){
        TrieNode* temp = root;
        for(int i = 0; i < word.length(); i++){
            int index = word[i] - 'a';
            if(temp->children[index] == NULL){                      // char is not present
                temp->children[index] = new TrieNode();
            }
            temp = temp->children[index];
            temp->commonPrefixNames.insert(word);
        }
        temp->isTerminated = true;
    }

    // return boolean result of "is the given string present in the trie or not?"
    bool isPresentHelper(TrieNode* root, string word){
        TrieNode* temp = root;
        for(int i = 0; i < word.length(); i++){
            int index = word[i] - 'a';
            if(temp->children[index] == NULL){                      // char is not present
                return false;
            }
            temp = temp->children[index];
        }
        return temp->isTerminated;
    }

    // prints all the distinct contacts which have the same prefix as given string in lexicographical increasing order
    void searchQueryHelper(TrieNode* root, string word, vector<vector<string>> &ans){
        TrieNode* temp = root;
        for(char x:word){
            int index = x - 'a';
            if(temp != NULL && temp->children[index] == NULL){
                // cout<<0;
                vector<string> tempVec;
                tempVec.push_back("0");
                ans.push_back(tempVec);
                temp = temp->children[index];
            }
            else if(temp == NULL){
                vector<string> tempVec;
                tempVec.push_back("0");
                ans.push_back(tempVec); 
            }
            else{
                temp = temp->children[index];
                vector<string> tempVec;
                for(auto itr = temp->commonPrefixNames.begin(); itr != temp->commonPrefixNames.end(); itr++){
                    
                    // cout<<temp->commonPrefixNames[i]<<" ";
                    // tempVec.push_back(temp->commonPrefixNames[i]);
                    tempVec.push_back(*itr);
                }
                // sort(tempVec.begin(), tempVec.end());
                ans.push_back(tempVec);
            } 
            // cout<<"\n";
        }
    }

    public:
    TrieNode* root;

    // constructor
    Trie(){
        root = new TrieNode();
    }

    // insert all the strings from the given array into Trie
    void insertIntoTrie(string contact[], int n){
        for(int i = 0; i < n; i++){
            insertIntoTrieHelper(root, contact[i]);
        }
    }

    // return boolean result of "is the given string present in the trie or not?"
    bool isPresent(string word){
        return isPresentHelper(root, word);
    }

    // prints all the distinct contacts which have the same prefix as given string in lexicographical increasing order
    void searchQuery(string word, vector<vector<string>> &ans){
        searchQueryHelper(root, word, ans);
    }

};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> ans;
        Trie* t = new Trie();
        t->insertIntoTrie(contact,n);
        t->searchQuery(s,ans);
        return ans;
    }
};