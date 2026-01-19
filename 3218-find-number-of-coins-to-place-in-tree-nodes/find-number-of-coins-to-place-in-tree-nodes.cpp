class Solution {
public:
    
    pair<long long,vector<long long>> m(vector<long long> num){

        int n = num.size();
        if(n<=2){
            return {1,num};
        }
        if(n==3){
            long long pro = (num[0]*num[1]*num[2]);
            if(pro<0) return {0,num};
            else return {pro,num};
        }
        if(n==4 || n==5){
            long long pro1 = num[n-3]*num[n-2]*num[n-1];
            long long pro2 = num[0]*num[1]*num[n-1];
            long long p = max(pro1,pro2);
            if(p<0) return {0,num};
            else return {p,num};
        }
        else{
            long long pro1 = num[n-3]*num[n-2]*num[n-1];
            long long pro2 = num[0]*num[1]*num[n-1];
            long long p = max(pro1,pro2);
            vector<long long> n_num(5);
            n_num[0]=num[0];
            n_num[1]=num[1];
            n_num[2]=num[n-3];
            n_num[3]=num[n-2];
            n_num[4]=num[n-1];
            if(p<0) return {0,n_num};
            else return {p,n_num};
        }
    }
    vector<long long> func(int node , int parent , vector<vector<long long>> &adj , vector<int>& cost, vector<long long>& coins  ){

        if(node != 0 && adj[node].size() == 1){
            coins[node]=1;
            //cout<<node<<" ";



            return {cost[node]};
        }

        vector<long long> num = {cost[node]};
        for(auto nextNode : adj[node]){
            if(nextNode == parent) continue;
            vector<long long> callback = func(nextNode , node ,  adj , cost , coins);
            //update num
            num.insert(num.end(), callback.begin(), callback.end());
            

        }
        

        sort(num.begin(),num.end());
        pair<long long,vector<long long>> ret = m(num);
        coins[node]=ret.first;
        return ret.second;
    }
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        
        int n = edges.size()+1;
        vector<vector<long long>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<long long> coins(n,1);
        func(0,-1,adj,cost,coins);
        return coins;
    }
};