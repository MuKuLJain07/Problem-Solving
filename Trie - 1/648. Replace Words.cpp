class TrieNode{
    public:
    bool isTerminated;
    TrieNode* children[26];

    TrieNode(){
        this->isTerminated = false;
        for(int i = 0; i < 26; i++){
            this->children[i] = NULL;
        }
    }
};

class Trie{
    private:
    void insertIntoTrieHelper(TrieNode* root, string word){
        TrieNode* temp = root;
        for(int i = 0;i<word.length(); i++){
            int index = word[i] - 'a';
            if(temp->children[index] == NULL){
                temp->children[index] = new TrieNode();
            }
            temp = temp->children[index];
        }
        temp->isTerminated = true;
    }

    // find root word of the given successor
    void successorsWithRootHelper(TrieNode* root, string word, string &ans){
        TrieNode* temp = root;
        string rootWord="";
        for(int i = 0; i<word.length(); i++){
            int index = word[i] - 'a';
            if(temp!=NULL && temp->children[index] != NULL){
                temp = temp->children[index];
                if(temp->isTerminated == true){
                    rootWord+=word[i];
                    break;
                }
                else{
                    rootWord+=word[i];
                }
            }
            else{
                // rootWord+=x;
                rootWord+=word.substr(i, word.length());
                break;
            }
        }
        rootWord+=" ";
        ans+=rootWord;
    }

    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }

    void insertIntoTrie(vector<string>& dictionary){
        for(int i = 0; i<dictionary.size(); i++){
            insertIntoTrieHelper(root, dictionary[i]);
        }
    }

    void successorsWithRoot(string str, string &ans){
        vector<string> seperatedWord;
        string word;
        stringstream iss(str);
        while (iss >> word)
            seperatedWord.push_back(word);

        for(int i = 0; i < seperatedWord.size(); i++){
            successorsWithRootHelper(root,seperatedWord[i],ans);
        }
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* t = new Trie();
        t->insertIntoTrie(dictionary);

        string ans = "";
        t->successorsWithRoot(sentence, ans);
        return ans.substr(0,ans.length()-1);
    }
};