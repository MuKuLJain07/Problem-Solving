class Solution {
private: 
    bool isCyclicDFS(int src, vector<int> adj[], vector<bool> &visited, vector<bool> &pathVisited, stack<int> &s){
        visited[src] = true;
        pathVisited[src] = true;

        for(auto neighbour : adj[src]){
            if(!visited[neighbour]){
                if(isCyclicDFS(neighbour, adj, visited, pathVisited, s)) return true;
            }
            else if(pathVisited[neighbour]) return true;
        }

        pathVisited[src] = false;
        s.push(src);
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // creating adjacency list
        vector<int> adj[numCourses];
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }

        stack<int> s;
        vector<bool> visited(numCourses, false);
        vector<bool> pathVisited(numCourses, false);
        vector<int> ans;
        for(int i = 0 ; i < numCourses; i++){
            if(!visited[i]){
                if(isCyclicDFS(i, adj, visited, pathVisited, s)) return ans;
            }
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};


