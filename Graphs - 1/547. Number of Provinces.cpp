class Solution {
private:
    void DFS(vector<vector<int>>& isConnected, vector<bool> &visited, int start){
        visited[start] = true;
        for(int i = 0; i < isConnected.size(); i++){
            if(isConnected[start][i] == 1 && !visited[i]){
                DFS(isConnected, visited, i);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);

        int ans = 0;
        for(int i = 0; i < isConnected.size(); i++){
            if(!visited[i]){
                ans+=1;
                DFS(isConnected, visited, i);
            }    
        }

        return ans;
    }
};