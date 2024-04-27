class Solution{
    private:
        void dijikstra(int src, vector<pair<int,int>> adj[], vector<int> &distance){
            
            set<pair<int,int>> st;    // dist node
            
            distance[src] = 0;
            st.insert({0,src});
            
            while(!st.empty()){
                auto topNode = *(st.begin());
                
                int dist = topNode.first;
                int node = topNode.second;
                
                st.erase(st.begin());
                
                for(auto neighbour : adj[node]){
                    int neighbourData = neighbour.first;
                    int neighbourDist = neighbour.second;
                    
                    if((dist + neighbourDist) < distance[neighbourData]){
                        auto record = st.find({distance[neighbourData], neighbourData});
                        if(record != st.end()){             // data found
                            st.erase(record);
                        }
                        distance[neighbourData] = dist + neighbourDist;
                        st.insert({dist + neighbourDist, neighbourData});
                    }
                }
            }
            
            
        }
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            // create adjacency list
            vector<pair<int,int>> adj[n+1];    // data, dist
            
            
            for(int i = 0; i < edges.size(); i++){
                int u = edges[i][0];
                int v = edges[i][1];
                
                adj[u].push_back({v,0});
                adj[v].push_back({u,1});
            }
            
            vector<int> distance(n+1, INT_MAX);
            dijikstra(src, adj, distance);
            
            return distance[dst];
        }
};