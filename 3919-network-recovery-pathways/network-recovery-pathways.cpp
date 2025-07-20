class Solution {
public:

    bool valid(int mid, int n , vector<vector<pair<int, int>>> &adj, long long k ,vector<bool>& online){

        vector<long long> cost(n,LLONG_MAX);
        
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

        pq.push({0,0});
        cost[0]=0;

        while(!pq.empty()){
            int node = pq.top().second;
            long long path_cost = pq.top().first;
            pq.pop();
            if (path_cost > cost[node]) continue;
            if(node==n-1) return true;

            for(auto it : adj[node]){

                // edge cost zyada ho gayi
                if(it.second<mid) continue;


                int adj_node = it.first;
                long long new_path_cost = path_cost + it.second;
                //offline node ya k se zyada cost ho gayi
                if(online[adj_node]==false || new_path_cost>k) continue;
                
               

                if(new_path_cost<cost[adj_node]){
                    cost[adj_node]=new_path_cost;
                    pq.push({new_path_cost,adj_node});
                }
            }

        }
        return false;


    }
    
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
      
        
        vector<vector<pair<int, int>>> adj(n);
       
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            adj[u].push_back({v,cost});
        }

        
        int left =1;
        int right = 1e9;
        while (left < right) {
            
            int mid = left + (right - left + 1) / 2;  // bias to right

            if (valid(mid, n , adj, k , online)) {
                left = mid;  // mid might be the answer
            } else {
                right = mid - 1;
            }
        }
         // last value where condition is true
        if(valid(left,n,adj,k,online)) return left;
        else return -1;

        

        
    }
};