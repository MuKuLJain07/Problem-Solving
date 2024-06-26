class TrieNode{
    public:
    bool isTerminated;
    TrieNode* children[26];
    int commonPrefixNames;

    TrieNode(){
        this->isTerminated = false;
        for(int i = 0; i < 26; i++){
            this->children[i] = NULL;
        }
        this->commonPrefixNames = 0;
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
            temp->commonPrefixNames+=1;
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
    void searchQueryHelper(TrieNode* root, string word, int &ans){
        TrieNode* temp = root;
        for(char x:word){
            int index = x - 'a';
            temp = temp->children[index];
            ans+=(temp->commonPrefixNames);
        }

    }

    public:
    TrieNode* root;

    // constructor
    Trie(){
        root = new TrieNode();
    }

    // insert all the strings from the given array into Trie
    void insertIntoTrie(vector<string> &contact, int n){
        for(int i = 0; i < n; i++){
            insertIntoTrieHelper(root, contact[i]);
        }
    }

    // return boolean result of "is the given string present in the trie or not?"
    bool isPresent(string word){
        return isPresentHelper(root, word);
    }

    // prints all the distinct contacts which have the same prefix as given string in lexicographical increasing order
    void searchQuery(string word, vector<int> &ans){
        int tempAns = 0;
        // for(int i = 1; i<=word.size(); i++){
        //     searchQueryHelper(root, word.substr(0,i), tempAns);
        // } 
        searchQueryHelper(root, word, tempAns);

        ans.push_back(tempAns);
    }

};

// class Solution{
// public:
//     vector<vector<string>> displayContacts(int n, string contact[], string s)
//     {
//         vector<vector<string>> ans;
//         Trie* t = new Trie();
//         t->insertIntoTrie(contact,n);
//         t->searchQuery(s,ans);
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        Trie* t = new Trie();
        t->insertIntoTrie(words,words.size());
        
        // searching every possible query
        for(auto word: words){
            t->searchQuery(word,ans);
        }
        return ans;
    }
};