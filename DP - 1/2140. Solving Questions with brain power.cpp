// Recursion
class Solution {
public:
    long long mostPointsHelper(vector<vector<int>>& questions, int i){
        if(i >= questions.size()) return 0;
        long long take = questions[i][0] + mostPointsHelper(questions, i+questions[i][1]+1);
        long long notTake = 0 + mostPointsHelper(questions, i + 1);
        
        return max(take,notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        return mostPointsHelper(questions, 0);
    }
};

// Memoization
class Solution {
public:
    long long mostPointsHelper(vector<vector<int>>& questions, int i, vector<long long> &dp){
        if(i >= questions.size()) return 0;

        if(dp[i] != 0) return dp[i];

        long long take = questions[i][0] + mostPointsHelper(questions, i+questions[i][1]+1, dp);
        long long notTake = 0 + mostPointsHelper(questions, i + 1, dp);
        
        return dp[i] = max(take,notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0);
        return mostPointsHelper(questions, 0, dp);
    }
};

 
