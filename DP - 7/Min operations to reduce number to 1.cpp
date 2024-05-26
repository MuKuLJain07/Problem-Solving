// Given a positive integer n and 3 operations on n:

// n - 1
// n / 2 (if n is even)
// n / 3 (if n % 3 == 0)
// Find the minimum number of above operations to reduce n to 1.


#include <bits/stdc++.h>
using namespace std;

// Recursion
int minOp(int n){               // this function returns the minimum number of op on given integer n
    if(n <= 0) return INT_MAX;
    if(n==1) return 0;

    int op1 = minOp(n-1);
    
    int op2 = INT_MAX;
    if(n%2 == 0) op2 = minOp(n/2);

    int op3 = INT_MAX;
    if(n%3 == 0) op3 = minOp(n/3);

    return 1 + min(op1, min(op2, op3));
}


int main(){
    int n;
    cin >> n;
    cout<<"Min number of operations : " << minOp(n);
    return 0;
}



// Memoization
int minOp(int n, vector<int> &memo){               // this function returns the minimum number of op on given integer n
    if(n <= 0) return INT_MAX;
    if(n==1) return 0;

    if(memo[n] != -1) return memo[n];

    int op1 = minOp(n-1, memo);
    
    int op2 = INT_MAX;
    if(n%2 == 0) op2 = minOp(n/2, memo);

    int op3 = INT_MAX;
    if(n%3 == 0) op3 = minOp(n/3, memo);

    return memo[n] = 1 + min(op1, min(op2, op3));
}


int main(){
    int n;
    cin >> n;

    vector<int> memo(n+1,-1);
    cout<<"Min number of operations : " << minOp(n,memo);
    return 0;
}


// Tabulation
int minOp(int n){
    if(n <= 1) return 0;

    vector<int> dp(n+1,0);

    for(int i = 2; i < n+1; i++){
        if(i%2 == 0 && i%3 == 0){
            dp[i] = 1 + min(dp[i-1], min(dp[i/2], dp[i/3]));
        }
        else if(i%2 == 0){
            dp[i] = 1 + min(dp[i-1], dp[i/2]);
        }
        else if(i%3 == 0){
            dp[i] = 1 + min(dp[i-1], dp[i/3]);
        }
        else{
            dp[i] = 1 + dp[i-1];
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    cout<<"Min number of operations : " << minOp(n);
    return 0;
}