class Solution {    
    class TrieNode {
    public:
        TrieNode* next[2];
        int cnt;
        TrieNode () {
            next[0] = NULL;
            next[1] = NULL;
            cnt = 0;
        };
    };
    
    void insert(TrieNode* root, int num) {
        TrieNode* cur = root;
        for (int j = 14; j >= 0; j--) {
            int index = (num>>j) & 1;
            if (cur->next[index] == NULL)
                cur->next[index] = new TrieNode();
            cur = cur->next[index];
            cur->cnt++;
        }
    }
    
    int GetCount(TrieNode* root, int num, int limit) {
        TrieNode* cur = root;
        int cnt = 0;
        for (int j = 14; j >= 0; j--) {
            int bit_num = ((num >> j) & 1);
            int bit_limit = ((limit >> j) & 1);
            
            if (bit_limit == 1) {
                if (cur->next[bit_num] != NULL) {
                    cnt += cur->next[bit_num]->cnt;
                }
                cur = cur->next[1 - bit_num];
            } 
            else{
                cur = cur->next[bit_num];
            }
            
            if (cur == NULL) break;
        }
        return cnt;
    }
    
public:
    int countPairs(vector<int>& nums, int low, int high) {
        TrieNode* root = new TrieNode();
        
        int ans = 0;
        for (int num : nums) {
            ans += GetCount(root, num, high + 1) - GetCount(root, num, low);
            insert(root, num);
        }
        
        return ans;
    }
};