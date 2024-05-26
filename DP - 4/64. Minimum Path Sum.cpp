class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m==0 && n==0){
            return 0;
        }
        
        int cache[m][n];
        
        cache[0][0] = grid[0][0];

        for(int i = 1; i < m; i++){
            cache[i][0] = cache[i-1][0] + grid[i][0];
        }
        for(int i = 1; i < n; i++){
            cache[0][i] = cache[0][i-1] + grid[0][i];
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                cache[i][j] = grid[i][j] + min(cache[i-1][j], cache[i][j-1]);
            }
        }
        return cache[m-1][n-1];
    }
};