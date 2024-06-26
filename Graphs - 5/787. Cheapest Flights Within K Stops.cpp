class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // creating adj list
        vector<pair<int, int>> adj[n];
        for(auto flight :  flights){
            int u = flight[0];
            int v = flight[1];
            int c = flight[2];

            adj[u].push_back({v,c});
        }

        // djikstra
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;

        queue<pair<int, pair<int,int>>> q;       // stops, node, dist
        q.push({0,{src,0}});

        while(!q.empty()){
            pair<int, pair<int,int>> frontNode = q.front();
            int stop = frontNode.first;
            int nodeVal = frontNode.second.first;
            int distTravelled = frontNode.second.second;
            q.pop();

            if(stop > k) continue;           // number of stops have exceeded

            // traversing all the adj nodes
            for(auto neighbour : adj[nodeVal]){
                int neighbourVal = neighbour.first;
                int neighbourWt = neighbour.second;

                if(dist[neighbourVal] > neighbourWt + distTravelled){
                    dist[neighbourVal] = neighbourWt + distTravelled;
                    q.push({stop+1,{neighbourVal,neighbourWt + distTravelled}});
                }
            }

        }

        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};