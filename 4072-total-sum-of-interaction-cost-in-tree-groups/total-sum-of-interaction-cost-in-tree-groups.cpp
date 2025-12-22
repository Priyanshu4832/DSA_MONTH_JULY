class Solution {
public:

    vector<int> dfs(int u , int parent  , vector<int>& group , vector<vector<int>>&adj , vector<int>&total , long long & ans){

        vector<int> cnt(21,0);

        cnt[group[u]]++;

        for(auto v : adj[u]){
            if(v==parent) continue;

            vector<int> child = dfs(v,u,group,adj,total,ans);

            for(int g=0 ; g<=20 ; g++){
                long long left = child[g];
                long long right = total[g]-left;
                ans+=left*right;
            }

            for(int g=0 ; g<=20 ; g++){
                cnt[g]+=child[g];
            }
        }
        return cnt;
    }
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {

        
        vector<vector<int>> adj(n);
        vector<int> total(21,0);
        long long ans = 0;

        for(int i= 0 ; i<group.size() ; i++){
            total[group[i]]++;
        }

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        dfs(0,-1,group , adj , total ,ans);
        return ans;
        
    }
};