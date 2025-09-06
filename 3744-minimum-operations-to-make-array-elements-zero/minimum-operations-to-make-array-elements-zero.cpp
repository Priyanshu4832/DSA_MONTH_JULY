class Solution {
public:
vector<long long> powFour = {4,16,64,256,1024,4096,16384,65536,262144,1048576,4194304,16777216,67108864,268435456};
vector<long long> operation = {2,3,4,5,6,7,8,9,10,11,12,13,14,15};

    void totOp(vector<long long> &totalOperation){
        totalOperation[0]=5;

        for(int i = 1 ; i<14; i++){
            
            //16-1 -4 = 15-4 = 11
            long long gap = (powFour[i]-1) - powFour[i-1];
            // 11*2 = 22

            long long operationGap = 1LL*gap * operation[i-1];
            long long excessAdd = operationGap + operation[i];
            //cout<<" gap "<<gap<<" operationGap "<<operationGap<<" excessAdd "<<excessAdd<<endl;

            totalOperation[i] = totalOperation[i-1] + excessAdd;

        }
    }

    long long func(long long l , long long r , vector<long long> &totalOperation){

        long long a = -1 ;
        long long b = -1 ;
        l = l-1;
        for(int i = 13 ; i>=0 ; i--){
            if(r>=powFour[i]){

                long long excess = r-powFour[i];
                long long excessOperation = 1LL*excess*operation[i];

                a = excessOperation + totalOperation[i];
                cout<<r<<endl;
                //cout<<" excess "<<excess<<" excessOperation "<<excessOperation<<" a "<<a<<endl;
                r=-1;
            }

            if(l>=powFour[i]){
                long long excess = l-powFour[i];
                long long excessOperation = 1LL*excess*operation[i];

                b = excessOperation + totalOperation[i];
                break;
            }
        }

        if(b==-1){
            if(l==0) b=0;
            else if(l==1) b = 1;
            else if (l==2) b = 2;
            else if (l==3) b = 3;
        }
        if(a==-1){
            
            if(r==1) a = 1;
            else if (r==2) a = 2;
            else if (r==3) a = 3;
        }
        
        long long requiredOperation = (a-b);
        if(requiredOperation%2==0) return (a-b)/2;
        else return ((a-b)/2)+1;
    }


    long long minOperations(vector<vector<int>>& queries) {
        
        
        

        vector<long long> totalOperation(14);
        totOp(totalOperation);
        long long res = 0 ;

        for(int i = 0 ; i<queries.size() ; i++){

            long long l = queries[i][0];
            long long r = queries[i][1];

            long long a = func(l,r,totalOperation);
            res+=a;
        }

        // for(auto it : totalOperation){
        //     cout<<it<<" ";
        // }

        return res;

        

        
    }
};