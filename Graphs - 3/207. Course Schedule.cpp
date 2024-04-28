class Solution {
private: 
    bool isCyclic(int src, vector<int> adj[], vector<bool> &visited, vector<bool> &pathVisited){

        visited[src] = true;
        pathVisited[src] = true;

        for(auto neighbour : adj[src]){
            if(!visited[neighbour]){
                if(isCyclic(neighbour, adj, visited, pathVisited)) return true;
            }
            else if(pathVisited[neighbour]) return true;
        }

        pathVisited[src] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }

        // DFS to check cycle in the directed graph
        vector<bool> visited(numCourses, false);
        vector<bool> pathVisited(numCourses, false);
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(isCyclic(i, adj, visited, pathVisited)) return false;
            }
        }
        return true;

    }
};