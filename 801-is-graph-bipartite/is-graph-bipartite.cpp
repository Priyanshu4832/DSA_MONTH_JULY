class Solution {
public:
    bool func(int node , int col , vector<int> &color ,vector<vector<int>>& graph){
        color[node]=col;

        for(auto adjacentNode : graph[node] ){
            if(color[adjacentNode]==-1){
                if(func(adjacentNode , !col , color , graph)==false) return false;
            }
            else{
                if(color[adjacentNode]==col) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i = 0 ; i<n ; i++){
            if(color[i]==-1){
                if(func(i,0,color,graph)==false) return false;
            }
        }
        return true;
    }
};