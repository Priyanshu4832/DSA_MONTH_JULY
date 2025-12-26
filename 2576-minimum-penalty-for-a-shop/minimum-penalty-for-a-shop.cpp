class Solution {
public:
    int bestClosingTime(string customers) {
        
        int n = customers.size();
        int cnt_n=0;
        for(int i = 0 ; i<customers.size() ; i++) if(customers[i]=='N') cnt_n+=1;
        int cnt_y = n - cnt_n;

        int running_n=0;
        int running_y=0;
        int penanlty = n;
        int ans = n;
        for(int j = 0 ; j<=customers.size() ; j++){

            int a = running_n;
            int b = cnt_y-running_y;
            if(j<customers.size() && customers[j]=='N') running_n+=1;
            else running_y+=1;
            
            int tpenanlty=a+b;
            if(tpenanlty<penanlty){
                penanlty=tpenanlty;
                ans=j;
            } 
        }
        return ans;

    }
};