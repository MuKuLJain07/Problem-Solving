// Recursion
class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, std::vector<int>(amount+1, INT_MAX));

        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0) dp[0][i] = i / coins[0];
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= amount; j++){
                int notTake = dp[i-1][j];
                int take = INT_MAX;
                if(j - coins[i] >= 0 && dp[i][j - coins[i]] != INT_MAX){
                    take = 1 + dp[i][j - coins[i]];
                }
                dp[i][j] = min(take, notTake);
            }
        }
        int ans = dp[n-1][amount];
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};

