class Solution {
public:
    long long func(int total , int cnt01 , int cnt10,int flipCost, int swapCost, int crossCost){

        long long cost = 0;
        long long diminish = min(cnt01 , cnt10);
        long long left = total - 2*diminish;

        cost +=(swapCost*diminish);

        // three cases 
        long long temp=LLONG_MAX;
        //case 1 : all flips

        long long c1 = flipCost*left;

        // case 2 : flip + swap
        long long c2=LLONG_MAX;
        // if(left%2==0){
        //     c2 += (flipCost+swapCost)*(left/2);
        // }
        // else{
        //     c2 += ((flipCost+swapCost)*(left/2))  + flipCost;
        // }


        // case 3 : cross + swap

        long long c3=0;
        if(left%2==0){
            c3 += (crossCost+swapCost)*(left/2);
        }
        else{
            c3 += ((crossCost+swapCost)*(left/2))  + flipCost;
        }

        //cout<<cost<<endl;
        //cout<<c1<<" "<<c2<<" "<<c3<<endl;
        cost += min(c1,min(c2,c3));
        return cost;


    }
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        

        long long cnt01=0;
        long long cnt10=0;
        long long cost=0;

        for(int i=0 ; i<s.size() ; i++){

            if(s[i]!=t[i]){
                if(s[i]=='0') cnt01++;
                else cnt10++;
            }
        }

        long long total = cnt01 + cnt10;
        long long n = total;

        // three cases 
      
        //case 1 : all flips

        long long c1 = flipCost*total;


        // case 2 : flip + swap
        long long c2=LLONG_MAX;
        // if(n%2==0){
        //     c2 += (flipCost+swapCost)*(n/2);
        // }
        // else{
        //     c2 += ((flipCost+swapCost)*(n/2))  + flipCost;
        // }


        // case 3 : cross + swap

        long long c3=0;
        if(n%2==0){
            c3 += (crossCost+swapCost)*(n/2);
        }
        else{
            c3 += ((crossCost+swapCost)*(n/2))  + flipCost;
        }

        cost = min(c1,min(c2,c3));


        // case 4 : swapfirst then do these 3 cases
        long long temp = func(total , cnt01 , cnt10,flipCost, swapCost, crossCost);

        cost = min(cost,temp);

        return cost;
    }
};