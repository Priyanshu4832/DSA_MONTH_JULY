class Solution {
public:
    vector<long long> dijsktra(long long start , vector<vector<pair<long long, long long>>>  adj){

        int n = adj.size();
        vector<long long> dist(n,LLONG_MAX);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>> , greater<pair<long long, long long>> > pq;
        dist[start]=0;
        pq.push({0,start});

        while(!pq.empty()){
            long long cost = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            if(cost>dist[node]) continue;

            for(auto it : adj[node]){
                long long nxtNode = it.first;
                long long edgeWt = it.second;
                long long newCost = cost + edgeWt;

                if(newCost<dist[nxtNode]){
                    pq.push({newCost, nxtNode});
                    dist[nxtNode] = newCost;
                }
            }
        }
        return dist;

    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        
        vector<vector<pair<long long, long long>>> adj1(n);
        vector<vector<pair<long long, long long>>>   adj2(n);

        //sort(edges.begin() , edges.end());


        // for(int i=0 ; i<edges.size() ; i++){
        //     if(i!=0 && edges[i][0]==edges[i-1][0] && edges[i][1]==edges[i-1][1]) continue;
        //     else{
        //         long long from = edges[i][0];
        //         long long to = edges[i][1];
        //         long long wt = edges[i][2];
        //         adj1[from].push_back({to,wt});
        //         adj2[to].push_back({from,wt});
        //     }
        // }

        for(int i=0 ; i<edges.size() ; i++){
            long long from = edges[i][0];
            long long to = edges[i][1];
            long long wt = edges[i][2];
            adj1[from].push_back({to,wt});
            adj2[to].push_back({from,wt});
        }

        vector<long long> dis1 = dijsktra(src1, adj1);
        vector<long long> dis2 = dijsktra(src2, adj1);
        vector<long long> dis3 = dijsktra(dest, adj2);;

        long long ans = LLONG_MAX;

        // dist to dest from source 1 and 2 via intermediate node i
        // dist(src1,i) + dist(src2,i) + dist(i,dest);
        
        for(int i = 0 ; i<n ; i++){

            long long d1 = dis1[i];
            long long d2 = dis2[i];
            long long d3 = dis3[i];

            if (d1 == LLONG_MAX || d2 == LLONG_MAX || d3 == LLONG_MAX) continue;
            long long finalDist = d1+d2+d3;
            ans = min(ans,finalDist);
        }
        if(ans!=LLONG_MAX) return ans;
        else return -1;
    }
};