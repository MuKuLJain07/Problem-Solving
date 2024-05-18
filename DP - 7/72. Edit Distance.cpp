// Recursion
class Solution {
private:
    int minDistanceHelper(string word1, string word2, int i, int j){
        if(i == word1.length()){
            return word2.length()-j;
        }
        if(j == word2.length()){
            return word1.length()-i;
        }

        if(word1[i] == word2[j]){
            return minDistanceHelper(word1, word2, i+1, j+1);
        }

        int dist1 = minDistanceHelper(word1, word2, i+1, j+1);
        int dist2 = minDistanceHelper(word1, word2, i, j+1);
        int dist3 = minDistanceHelper(word1, word2, i+1, j);
          
        return min(dist1,min(dist2,dist3)) +1;
    }
public:
    int minDistance(string word1, string word2) {
        return minDistanceHelper(word1, word2, 0, 0);
    }
};

// Memoization
class Solution {
private:
    int minDistanceHelper(string word1, string word2, int i, int j, vector<vector<int>> dp){
        if(i == word1.length()){
            return word2.length()-j;
        }
        if(j == word2.length()){
            return word1.length()-i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = INT_MAX;
        if(word1[i] == word2[j]){
            ans = minDistanceHelper(word1, word2, i+1, j+1,dp);
        }
        else{
            int dist1 = minDistanceHelper(word1, word2, i+1, j+1,dp);
            int dist2 = minDistanceHelper(word1, word2, i, j+1,dp);
            int dist3 = minDistanceHelper(word1, word2, i+1, j,dp);
            ans = min(dist1,min(dist2,dist3)) + 1;
        }
        
        dp[i][j] = ans;
        return dp[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, -1));

        return minDistanceHelper(word1, word2, 0, 0,dp);
    }
};

// Dp
class Solution {
 public:
  int minDistance(string word1, string word2) {
    const int m = word1.length();//first word length
    const int n = word2.length();//second word length
    // dp[i][j] := min # of operations to convert word1[0..i) to word2[0..j)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; ++i)
      dp[i][0] = i;

    for (int j = 1; j <= n; ++j)
      dp[0][j] = j;

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (word1[i - 1] == word2[j - 1])//same characters
          dp[i][j] = dp[i - 1][j - 1];//no operation
        else
          dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                             //replace       //delete        //insert
    return dp[m][n];
  }
};