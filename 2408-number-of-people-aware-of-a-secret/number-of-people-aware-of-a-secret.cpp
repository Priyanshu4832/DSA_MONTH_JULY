class Solution {
public:

    // void printA(vector<vector<long long>> &simulation){
    //     for(int i = 0 ; i<simulation.size() ; i++){
    //         for(int j = 0 ; j<simulation[0].size() ; j++){
    //             cout<<simulation[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        int mod = 1000000007;
        vector<vector<long long>> simulation(delay+1 , vector<long long>(forget+1,0));

        simulation[delay][forget]=1;
        //cout<<"day 1"<<endl;
        //printA(simulation);

        for(int i=2 ; i<=n ; i++){

           

            int goTill = forget-delay;
            for(int k = 0 ; k<goTill ; k++){
                simulation[0][k] = simulation[0][k+1];
            }

            int r = 0 ;
            int c = goTill;
            while(r<delay && c<forget){

                simulation[r][c] = simulation[r+1][c+1];
                r++;
                c++;
            }
            simulation[delay][forget]=0;
            
            long long cnt = 0;
            for(int k = 1 ; k<=goTill ; k++){
                cnt=(cnt+simulation[0][k])%mod;
            }

            simulation[delay][forget]=cnt;
            //cout<<"day "<<i<<endl;
            //printA(simulation);

        }



        long long res=0;
        int goTill = forget-delay;
        for(int i = 1 ; i<=goTill ; i++){
            res=( res+simulation[0][i])%mod;
        }
        int r = 1;
        int c = goTill+1;
        while(r<=delay && c<=forget){
            res=( res+simulation[r][c])%mod;
            r++;
            c++;
        }

        return res;
    }
};