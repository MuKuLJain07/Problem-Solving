#include <bits/stdc++.h>
using namespace std;

int minCoinsNeeded(int n, vector<int> &coins, int x){
    vector<vector<int>> dp(n, vector<int>(x+1,0));

    for(int i = 0; i < x+1; i++){
        if(i % coins[0] == 0){
            dp[0][i] = i / coins[0];
        }
        else{
            dp[0][i] = 1e9;
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < x+1; j++){

            int take = INT_MAX;
            if(j >= coins[i]){
                take = 1 + dp[i][j-coins[i]];
            }
            int notTake = 0 + dp[i-1][j];

            dp[i][j] = min(take, notTake);
        }
    }
    return dp[n-1][x];
}

int main(){
    int n,x;
    cin >> n >> x;

    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    int ans = minCoinsNeeded(n, coins, x);
    if(ans == INT_MAX || ans == 1e9) cout<<-1;
    else cout<<ans;
    return 0;
}