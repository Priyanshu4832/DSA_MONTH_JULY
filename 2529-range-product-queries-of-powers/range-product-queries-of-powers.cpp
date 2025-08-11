class Solution {
public:

    vector<int> powArr(int n){

        vector<int> temp;
        while(n>0){
            int rem = n%2;
            temp.push_back(rem);
            n= n/2;

        }


        //reverse(temp.begin(), temp.end());
        vector<int> newArr;
        for(int i =0 ; i<temp.size() ; i++){
            if(temp[i]==1){
                temp[i] =  1<<i;
                newArr.push_back(1<<i);
            }
        }
        return newArr;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        
        int mod = 1000000007;
        vector<int> a = powArr(n);



        vector<int> prefix(a.size());
        prefix[0]=a[0];
        for(int i=1 ; i<a.size() ; i++){

            prefix[i]=(a[i]*prefix[i])%mod;
        }


        // vector<int> res;
        // for(auto it : queries){

        //     if(it[0]==0){
        //         int cal = prefix[it[1]];
        //         res.push_back(cal);
        //     }
        //     else{
        //         int cal = (prefix[it[1]]/prefix[it[0]-1])%mod;
        //         res.push_back(cal);
        //     }
            

        // }
        
        vector<int> res;
        for(auto it : queries){
            int pro = 1;
            for(int i=it[0] ; i<=it[1] ; i++){
                pro = (1LL*pro * a[i])%mod;
            }
            res.push_back(pro);
            

        }
        return res;
    }
};