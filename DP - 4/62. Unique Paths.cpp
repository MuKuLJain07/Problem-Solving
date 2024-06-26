class Solution {
public:
    int uniquePaths(int m, int n) {

        if(m==0 && n==0){
            return 0;
        }
        
        int cache[m][n];
        

        cache[0][0] = 0;
        for(int i = 0; i < m; i++){
            cache[i][0] = 1;
        }
        for(int i = 0; i < n; i++){
            cache[0][i] = 1;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                cache[i][j] = cache[i-1][j] + cache[i][j-1];
            }
        }
        return cache[m-1][n-1];
    }
};