class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
  
        vector<pair<int, int>> adj[m][n];

        // creating adjacency 2D list
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){               // left right
                    if(j-1 >= 0 && (grid[i][j-1] == 4 || grid[i][j-1] == 6 || grid[i][j-1] == 1) ){
                        adj[i][j].push_back({i,j-1});
                    }
                    if(j+1 < n && (grid[i][j+1] == 3 || grid[i][j+1] == 5 || grid[i][j+1] == 1)){
                        adj[i][j].push_back({i,j+1});
                    }
                }
                if(grid[i][j] == 2){              // up down
                    if(i-1 >= 0 && (grid[i-1][j] == 4 || grid[i-1][j] == 3 || grid[i-1][j] == 2)){
                        adj[i][j].push_back({i-1,j});
                    }
                    if(i+1 < m && (grid[i+1][j] == 5 || grid[i+1][j] == 6 || grid[i+1][j] == 2)){
                        adj[i][j].push_back({i+1,j});
                    }
                }
                if(grid[i][j] == 3){               // left bottom
                    if(j-1 >= 0 && (grid[i][j-1] == 4 || grid[i][j-1] == 6 || grid[i][j-1] == 1)){
                        adj[i][j].push_back({i,j-1});
                    }
                    if(i+1 < m && (grid[i+1][j] == 5 || grid[i+1][j] == 6 || grid[i+1][j] == 2)){
                        adj[i][j].push_back({i+1,j});
                    }
                }
                if(grid[i][j] == 4){              // right bottom   
                    if(j+1 < n && (grid[i][j+1] == 1 || grid[i][j+1] == 3 || grid[i][j+1] == 5)){
                        adj[i][j].push_back({i,j+1});
                    }
                    if(i+1 < m && (grid[i+1][j] == 2 || grid[i+1][j] == 5 || grid[i+1][j] == 6)){
                        adj[i][j].push_back({i+1,j});
                    }
                }
                if(grid[i][j] == 5){              // left up
                    if(j-1 >= 0 && (grid[i][j-1] == 4 || grid[i][j-1] == 6 || grid[i][j-1] == 1)){
                        adj[i][j].push_back({i,j-1});
                    }
                    if(i-1 >= 0 && (grid[i-1][j] == 3 || grid[i-1][j] == 4 || grid[i-1][j] == 2)){
                        adj[i][j].push_back({i-1,j});
                    }
                }
                if(grid[i][j] == 6){                // right up
                    if(j+1 < n && (grid[i][j+1] == 3 || grid[i][j+1] == 5 || grid[i][j+1] == 1)){
                        adj[i][j].push_back({i,j+1});
                    }
                    if(i-1 >= n && (grid[i-1][j] == 3 || grid[i-1][j] == 4 || grid[i-1][j] == 2)){
                        adj[i][j].push_back({i-1,j});
                    }
                }
            }
        }

        // BFS
        queue <pair<int,int>> q;

        vector<vector<bool>> visited(m, vector<bool>(n,false));

        q.push({0,0});
        visited[0][0] = true;


        while(!q.empty()){
            pair<int,int> frontNode = q.front();
            int row = frontNode.first;
            int col = frontNode.second;
            q.pop();

            if(row == m-1 && col == n-1){           // way to exit is found
                return true;
            }

            for(auto neighbour : adj[row][col]){
                if(!visited[neighbour.first][neighbour.second]){
                    q.push({neighbour.first, neighbour.second});
                    visited[neighbour.first][neighbour.second] = true;
                }
            }
        }
        return false;
    }
};