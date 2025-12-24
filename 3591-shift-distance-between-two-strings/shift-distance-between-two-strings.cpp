class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        

        vector<long long> next(27,0);
        vector<long long> back(28,0);
        next[1]=nextCost[0];
        back[26]=previousCost[25];

        for(long long i=2 ; i<=26 ; i++){
            next[i]=next[i-1]+nextCost[i-1];
        }
        for(long long i=25 ; i>=1 ; i--){
            back[i]=back[i+1]+previousCost[i-1];
        }

        // for(auto it : next) cout<<it<<" ";
        // cout<<endl;
        // for(auto it : back) cout<<it<<" ";
        // cout<<endl;

        long long ans = 0 ;
        for(long long i=0 ; i<s.size() ; i++){

            long long pos1 = s[i]-'`';
            long long pos2 = t[i]-'`';
            long long cost1 = 1LL;
            long long cost2 = 1LL;

            if(s[i]==t[i]) continue;

            else if(s[i]<t[i]){
                // way 1 is just move forward and i need is its prfix sum one positon back 
                // c->e is by prefix sum b->d
                cost1 = next[pos2-1]-next[pos1-1];

                //way 2 is move back to a then z and then to character
             
                cost2 = ( back[1]-back[pos1+1] ) + (  back[pos2+1]  );
                //cout<<s[i]<<" -> "<<t[i]<<" cost1:"<<cost1<<" cost2:"<<cost2<<endl;
            }

            else if(s[i]>t[i]){
                // way 1 is move back 
                
                cost1 = back[pos2+1]-back[pos1+1];
            

                // way 2 is just move back

                // cost 2 = ( z->a change that is nextCost[25] and then cost to move till a char from a ) + ( from char till last )
                cost2 = ( nextCost[25]+next[pos2-1]  ) + (  next[25]-next[pos1-1] );
                //cout<<s[i]<<" -> "<<t[i]<<" cost1:"<<cost1<<" cost2:"<<cost2<<endl;

            }
            ans+=min(cost1,cost2);
        }

        return ans;

    }
};