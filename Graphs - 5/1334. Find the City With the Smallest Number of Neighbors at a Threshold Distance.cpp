class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // creating adj matrix for the given graph
        vector<vector<int>> adj(n,vector<int>(n,INT_MAX));

        for(int i = 0 ; i < n; i++){
            adj[i][i] = 0;
        }

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u][v] = w;
            adj[v][u] = w;
        }

        // shortest path b/w all the pair of nodes (Floyd Warshal)
        for(int k = 0; k < n; k++){
            for(int i = 0 ; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(adj[i][k] == INT_MAX || adj[k][j] == INT_MAX){
                        continue;
                    }
                    else adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }

        // checking the cities that can be reached within the threshold
        int city = 0;
        int reachable = INT_MAX;
        for(int i = 0; i < n; i++){
            int temp = 0;
            for(int j = 0 ; j < n; j++){
                if(i!=j && adj[i][j] <= distanceThreshold) temp+=1;
            }
            if(reachable >= temp){
                city = i;
                reachable = temp;
            }
        }
        return city;
    }
};