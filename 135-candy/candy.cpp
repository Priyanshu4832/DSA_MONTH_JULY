class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        int req = 0;
        vector<int> given(n,1);

        for(int i=0 ; i<n-1 ; i++){
            if(ratings[i]>ratings[i+1]){
                if(given[i]<=given[i+1]){
                    given[i]++;
                }
                int k = i;
                while(k>0 && given[k]==given[k-1] && ratings[k-1]>ratings[k]) {
                    given[k-1]++;
                    k--;
                }
            }
            else if(ratings[i]<ratings[i+1]){
                given[i+1]+=given[i];
            }

        }
        
        for(int i = 0 ; i<n ; i++){
            req+=given[i];
        }
        return req;
    }
};