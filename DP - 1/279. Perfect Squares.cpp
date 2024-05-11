// Recursion --> exponential time complexity
// class Solution {
// public:
//     int numSquares(int n){
//         if(n==0) return 0;

//         int ans = 1e9;
//         for(int i = 1 ; i*i <= n; i++){
//             int temp = numSquares(n-(i*i));
//             ans = min(ans,temp+1);
//         }

//         return ans;
//     }
// };


// memoization
// class Solution {
// public:
//     int solve(int n, vector<int> &dp){
//         if(n==0) return 0;
//         if(dp[n] != -1) return dp[n];

//         int ans = 1e9;
//         for(int i = 1 ; i*i <= n; i++){
//             int temp = solve(n-(i*i),dp);
//             ans = min(ans,temp+1);
//         }

//         dp[n] = ans;
//         return dp[n];
//     }
//     int numSquares(int n) {
//         vector<int> dp(n+1,-1);
//         return solve(n,dp);
//     }
// };

// tabulation
class Solution {
public:
    int solve(int n){
        vector<int> dp(n+1,1e9);

        dp[0] = 0;

        for(int i = 1 ; i <= n; i++){
            for(int j = 1; j*j <= i; j++){  
                dp[i] = min(dp[i],1+dp[i-(j*j)]);
            }
        }

        return dp[n];
    }
    int numSquares(int n) {
        return solve(n);
    }
};