class Solution {
private:
    bool isValid(int m, int n, int x, int y){
        if(x>=0 && x<m && y>=0 && y<n) return 1;
        return 0;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();            // rows
        int n = heights[0].size();         // colums

        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[0][0] = 0;

        // djikstra algo
        set<pair<int,pair<int,int>>> st;                 //abs-difference, row, col
        st.insert({0,{0,0}});

        while(!st.empty()){
            pair<int,pair<int,int>> frontNode = *(st.begin());
            int diff = frontNode.first;
            int row = frontNode.second.first;
            int col = frontNode.second.second;

            st.erase(st.begin());

            int nr[4] = {-1,0,1,0};
            int nc[4] = {0,1,0,-1};
            for(int i = 0; i < 4; i++){
                int x = row + nr[i];
                int y = col + nc[i];

                if(isValid(m,n,x,y)){
                    if(dist[x][y] > max(dist[row][col], abs(heights[row][col] - heights[x][y]))){
                        dist[x][y] = max(dist[row][col], abs(heights[row][col] - heights[x][y]));
                        st.insert({dist[x][y],{x,y}});
                    }
                }
            }
        }

        return dist[m-1][n-1];
    }
};