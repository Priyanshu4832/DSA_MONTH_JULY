class DisjointSet {
    vector<int> rank,parent;
    int components;
public:
    DisjointSet(int n){
        rank.resize(n , 0);
        parent.resize(n);
        components=n;
        for(int i=0 ;i<n ;i++){
            parent[i]=i;
            
        }
    }
    
    int findPar(int node){
        if(node==parent[node]){
            return node;
        }
        
        return parent[node]=findPar(parent[node]);
    }
    
    void UnionByRank(int u,int v){
        
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        
        if(ulp_u==ulp_v) return;
        components--;
        
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
            
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    int compo(){
        return components;
    }
  
    
    
};
class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        
        long long n = nums.size();
        vector<long long> ans(n,0);

        DisjointSet ds(n);
        map<long long , long long > mpp;
        long long maxi = 0;

        for(long long i = n-1 ; i>=0 ; i--){

            long long idx = removeQueries[i];
            long long val = nums[idx];
            mpp[idx]=val;

            // if it has left member and right meber
            if(mpp.find(idx-1)!=mpp.end() &&  mpp.find(idx+1)!=mpp.end()){

                long long leftSum = mpp[ds.findPar(idx-1)];
                long long rightSum = mpp[ds.findPar(idx+1)];
                ds.UnionByRank(idx-1,idx);
                ds.UnionByRank(idx+1,idx);

                long long newSum = leftSum+rightSum+nums[idx];
                mpp[ds.findPar(idx)]=newSum;
                maxi = max(maxi,newSum);
                ans[i]=maxi;


            }
            //if it has left member
            else if(mpp.find(idx-1)!=mpp.end()){

                
                long long ult_p = ds.findPar(idx-1);
                long long newSum = val + mpp[ult_p];

                ds.UnionByRank(idx,idx-1);

                ult_p = ds.findPar(idx-1);
                mpp[ult_p]=newSum;


                maxi = max(maxi,newSum);
                ans[i]=maxi;
            }
            // if it has right member
            else if(mpp.find(idx+1)!=mpp.end()){
                
                long long ult_p = ds.findPar(idx+1);
                long long newSum = val + mpp[ult_p];

                ds.UnionByRank(idx,idx+1);
                ult_p = ds.findPar(idx+1);
                mpp[ult_p]=newSum;

                maxi = max(maxi,newSum);
                ans[i]=maxi;
            }
            // no member
            else{
                mpp[idx]=val;
                maxi = max(maxi,val);
                ans[i]=maxi;
            }
        }
        for(long long i=0 ; i<n-1 ; i++){
            ans[i]=ans[i+1];
        }
        ans[n-1]=0;
        return ans;
    }
};