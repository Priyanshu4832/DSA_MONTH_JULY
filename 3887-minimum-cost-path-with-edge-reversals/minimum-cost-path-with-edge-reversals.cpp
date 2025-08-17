class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],2*it[2]});
        }


        vector<int> dist(n,1e9);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[0]=0;
        pq.push({0,0});

        while(!pq.empty()){

            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(node==n-1) return cost;


            for(auto it : adj[node]){

                int newCost = cost + it.second;
                int adjNode = it.first;

                if(newCost<dist[adjNode]){
                    dist[adjNode]=newCost;
                    pq.push({newCost,adjNode});
                }
            }
        }
        return -1;
    }
};