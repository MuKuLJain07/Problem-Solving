class Solution
{
    private:
    void DFS(int src, vector<vector<int>>& adj, vector<bool> &vis, stack<int> &s){
        vis[src] = true;
        
        for(auto nbr : adj[src]){
            if(!vis[nbr]){
                DFS(nbr,adj,vis,s);
            }
        }
        
        s.push(src);
    }
    void rDFS(int src, vector<int> adj[], vector<bool> &vis){
        vis[src] = true;
        
        for(auto nbr : adj[src]){
            if(!vis[nbr]){
                rDFS(nbr,adj,vis);
            }
        }
        
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<bool> visited(V,false);
        stack<int> s;
        
        // creating topo sort
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                DFS(i,adj,visited,s);
            }
        }
        
        // Reversing each and every edge in the graph
        vector<int> reverseAdj[V];
        for(int i = 0; i < V; i++){
            for(int j = 0; j < adj[i].size(); j++){
                reverseAdj[adj[i][j]].push_back(i);
            }
        }
        
        
        for(int i = 0; i < V; i++){
            visited[i] = false;
        }
        
        int count = 0;
        while(!s.empty()){
            int topEle = s.top();
            s.pop();
            if(!visited[topEle]){
                count++;
                rDFS(topEle, reverseAdj, visited);
            }
        }
        
        return count;
    }
};