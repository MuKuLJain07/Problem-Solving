class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(m == 0 && n == 0) return 0;
        if(obstacleGrid[m-1][n-1] == 1) return 0;

        vector<vector<int>> memo(m, vector<int> (n));

        // initialization
        if(obstacleGrid[0][0] == 1) return 0;
        memo[0][0] = 1;

        for(int i = 1; i < m; i++){
            if(obstacleGrid[i][0] == 1){
                for(int j = i; j < m; j++){
                    memo[j][0] = 0;
                }
                break;
            }
            memo[i][0] = 1;
        }

        for(int i = 1; i < n; i++){
            if(obstacleGrid[0][i] == 1){
                for(int j = i; j < n; j++){
                    memo[0][j] = 0;
                }
                break;
            }
            memo[0][i] = 1;
        }


        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    memo[i][j] = 0;
                }
                else{
                    memo[i][j] = memo[i-1][j] + memo[i][j-1];
                }
            }
        }

        return memo[m-1][n-1];
    }
};