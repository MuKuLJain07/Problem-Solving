class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int m = grid.size();               // rows
	    int n = grid[0].size();           // columns
	    
	    vector<vector<int>> ans(m,vector<int>(n));
	    vector<vector<bool>> visited(m,vector<bool>(n, false));
	    
	    queue <pair<int, pair<int, int>>> q;
	    
	    for(int i = 0; i < m; i++){
	        for(int j = 0; j < n; j++){
	            if(grid[i][j] == 1){
	                q.push({0,{i,j}});
	                visited[i][j] = true;
	            }
	        }
	    }
	    
	    int updateRow[] = {-1,0,+1,0};
	    int updateCol[] = {0,1,0,-1};
	    
	    while(!q.empty()){
	        pair<int, pair<int, int>> node = q.front();
	        int dist = node.first;
	        int row = node.second.first;
	        int col = node.second.second;
	        
	        q.pop();
	        
	        ans[row][col] = dist;
	        
	        for(int i = 0; i < 4; i++){
	            int nr = row + updateRow[i];
	            int nc = col + updateCol[i];
	            if(nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc]){
	                q.push({dist+1,{nr,nc}});
	                visited[nr][nc] = true;
	            }
	            
	        }
	        
	    }
	    return ans;
	}
};