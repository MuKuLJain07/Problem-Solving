class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int head = 0;
        int tail = 0;
        int ans = 0;
        int cost = 0;

        for(int head = 0; head<s.length(); head++){
            cost+=abs(s[head]-t[head]);
            while(cost > maxCost){
                cost-=abs(s[tail]-t[tail]);
                tail+=1;
            }
            ans = max(ans,head-tail+1);
        }
        return ans;
    }
};