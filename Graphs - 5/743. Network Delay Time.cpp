class Solution {
private:
    vector <int> dijkstra(int V, vector<pair<int,int>> adj[], int S)
    {
        vector<int> distance(V+1, INT_MAX);
        
        set<pair<int,int>> st;                // dist, node
        distance[S] = 0;
        st.insert({0,S});
        
        while(!st.empty()){
            auto top = *(st.begin());
            
            int dist = top.first;
            int node = top.second;
            
            st.erase(st.begin());
            
            for(auto neighbour : adj[node]){
                int neighbourDistance = neighbour.second;
                int neighbourData = neighbour.first;
                
                if((dist + neighbourDistance) < distance[neighbourData]){
                    
                    // find if record already exists in the set
                    auto record = st.find({distance[neighbourData], neighbourData});
                    if(record != st.end()){
                        st.erase(record);
                    }
                    
                    distance[neighbourData] = dist+neighbourDistance;
                    st.insert({dist+neighbourDistance,neighbourData});
                }
            }
        }
        
        
        return distance;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // creating adj list
        vector<pair<int,int>> adj[n+1];
        for(auto time : times){
            int u = time[0];
            int v = time[1];
            int w = time[2];

            adj[u].push_back({v,w});
        }

        vector<int> time;
        time = dijkstra(n,adj,k);

        int ma = *max_element(time.begin()+1,time.end());
        if(ma == INT_MAX) return -1;
        return ma;
    }
};