class Solution {
private:
    vector<int> BFS(int src, vector<int> adj[], int n){
        vector<int> trav;

        queue<int> q;
        vector<bool> visited(n,false);

        visited[src] = true;
        q.push(src);

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto neighbour : adj[frontNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                    trav.push_back(neighbour);
                }
            }
        }

        return trav;
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans;

        vector<int> adj[n];
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[v].push_back(u);
        }

        for(int i = 0; i < n; i++){
            vector<int> ancestors = BFS(i,adj,n);
            sort(ancestors.begin(), ancestors.end());
            ans.push_back(ancestors);
        }
        return ans;
    }
};