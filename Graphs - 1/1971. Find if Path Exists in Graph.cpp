class Solution {
private:
    bool DFS(int n, vector<vector<int>> &adj, int source, int destination, vector<bool> &visited){
        if(source == destination){
            return true;
        }
        visited[source] = true;

        for(auto x : adj[source]){
            if(!visited[x]){
                if( DFS(n, adj, x, destination, visited) ){
                    return true;
                }
            }
        }
        return visited[destination];
    }
    void populateList(vector<vector<int>> &adj, vector<vector<int>>& edges){
        for(int i = 0 ; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // creating adjacency list
        vector<vector<int>> adj(n);
        populateList(adj,edges);

        // DFS
        vector<bool> visited(n,false);
        return DFS(n, adj, source, destination, visited);
    }
};