class Solution {
public:
    void DFS(vector<vector<char>>& grid, int row, int col){
        grid[row][col] = '0';

        if(row-1 >= 0 && grid[row-1][col] == '1'){
            DFS(grid, row-1, col);
        }
        if(row+1 < grid.size() && grid[row+1][col] == '1'){
            DFS(grid, row+1, col);
        }
        if(col-1 >= 0 && grid[row][col-1] == '1'){
            DFS(grid, row, col-1);
        }
        if(col+1 < grid[0].size() && grid[row][col+1] == '1'){
            DFS(grid, row, col+1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    ans+=1;
                    DFS(grid, i, j);
                }
            }
        }
        return ans;
    }
};