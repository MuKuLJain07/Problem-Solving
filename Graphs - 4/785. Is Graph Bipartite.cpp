class Solution {
public:
    bool isBipartiteHelper(int src, int V, vector<vector<int>>& graph, vector<int> &color, vector<bool> &visited){
        color[src] = 0;
        visited[src] = true;

        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto neighbour : graph[frontNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    color[neighbour] = !color[frontNode];
                    visited[neighbour] = true;
                }
                else{
                    if(color[neighbour] == color[frontNode]) return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V,-1);
        vector<bool> visited(V,false);
        for(int i = 0 ; i < V; i++){
            if(!visited[i]){
                if(!isBipartiteHelper(i, V, graph, color, visited)) return false;
            }
        }
        return true;
    }
};