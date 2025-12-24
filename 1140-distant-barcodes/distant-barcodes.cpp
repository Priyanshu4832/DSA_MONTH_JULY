class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        
        priority_queue<pair<int,int>> pq;

        unordered_map<int,int> mpp;
        for(auto it : barcodes) mpp[it]++;
        for(auto it : mpp) pq.push({it.second,it.first});


        int n = barcodes.size();
        vector<int> ans(n);
        int i=0;
        while(i<n){

            auto p = pq.top();
            pq.pop();

            int val=p.second;
            int freq = p.first;

            if(i!=0){
                if(ans[i-1]!=val){
                    ans[i]=val;
                    if(freq-1!=0) pq.push({freq-1,val});
                }
                else{
                    auto q = pq.top();
                    pq.pop();
                    pq.push({freq,val});
                    ans[i]=q.second;
                    if(q.first-1!=0) pq.push({q.first-1,q.second});
                }
            }
            else{
                ans[i]=val;
                if(freq-1!=0) pq.push({freq-1,val});
            }

            i+=1;
        }
        return ans;
    }
};