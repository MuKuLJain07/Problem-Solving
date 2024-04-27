class Solution {
  private:
    bool isCyclicHelper(int src, vector<int> adj[], vector<bool> &visited, vector<bool> &pathVisited){
        
        visited[src] = true;
        pathVisited[src] = true;
        
        for(auto neighbour : adj[src]){
            if(!visited[neighbour]){
                if(isCyclicHelper(neighbour, adj, visited, pathVisited)){
                    return true;
                }
            }
            else if(pathVisited[neighbour]){
                return true;
            }
        }
        
        pathVisited[src] = false;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(isCyclicHelper(i, adj, visited, pathVisited)) return true;
            }
        }
        
        return false;
    }
};