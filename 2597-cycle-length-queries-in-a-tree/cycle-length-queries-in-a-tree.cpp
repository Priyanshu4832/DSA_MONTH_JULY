class Solution {
public:

    int level(int num){

        int i = 0 ;
        for(int i = 0 ; i<=30 ; i++){
            int small = 1<<i;
            int big = (1<<(i+1))-1;
            if(num>=small && num<=big) return i;
        }
        return -1;
    }
    int func(int a , int b){
        int cnt = 0;
        int l1 = level(a);
        int l2 = level(b);


        if(l2>l1){
            for(int i = 0 ; i<(l2-l1) ; i++){
                b = b/2;
                cnt++;
            }
        }
        if(a==b) return cnt+1;
        while(true){
            
            if(a!=1){
                a = a/2;
                cnt++;
            }
            if(b!=1){
                b = b/2;
                cnt++;
            }
            if(a==b) break;
        }
        return cnt+1;
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;

        for(int i = 0 ; i<queries.size() ; i++){
            int a = queries[i][0];
            int b = queries[i][1];
            int small = min(a,b);
            int big = max(a,b);

            int c = func(small,big);
            ans.push_back(c);
        }
        return ans;
    }
};