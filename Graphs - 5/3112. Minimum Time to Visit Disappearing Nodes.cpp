class Solution {
private:
    vector<int> dijkstra(int n, vector<pair<int,int>> adj[], int src, vector<int>& disappear){
        vector<int> dist(n,INT_MAX);

        set<pair<int, int>> st;                        // dist, node
        dist[src] = 0;
        st.insert({0,src});

        while(!st.empty()){
            auto top = *(st.begin());

            int nodeDist = top.first;
            int nodeVal = top.second;

            st.erase(st.begin());

            for(auto nbr : adj[nodeVal]){
                int nbrDist = nbr.second;
                int nbrVal = nbr.first;

                if(nbrDist >= disappear[nbrVal]) continue;
                
                if(disappear[nbrVal] > nodeDist + nbrDist && dist[nbrVal] > nodeDist + nbrDist){
                    auto record = st.find({dist[nbrVal],nbrVal});

                    if(record != st.end()){
                        st.erase(record);
                    }
                    dist[nbrVal] = nodeDist + nbrDist;
                    st.insert({nodeDist + nbrDist, nbrVal});
                }
            }
        }
        return dist;
    }
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int> dist;
        if(n==0) return dist;
        
        vector<pair<int,int>> adj[n];

        // creating adj list
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        dist = dijkstra(n,adj,0,disappear);
        for(int  i = 0; i < n; i++){
            if(dist[i] >= disappear[i]){
                dist[i] = -1;
            }
        }
        return dist;
    }
};