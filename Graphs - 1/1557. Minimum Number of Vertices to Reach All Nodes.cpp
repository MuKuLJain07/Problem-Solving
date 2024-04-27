class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> inDegree(n);

        // populating indegree vector
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            inDegree[v]++;                   // storing edges in reverse order
        }

        for(auto i = 0; i < n; i++){
            if(inDegree[i] == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};