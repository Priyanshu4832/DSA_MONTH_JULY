class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        

        sort(basket1.begin(),basket1.end());
        sort(basket2.begin(),basket2.end());
        int flag=0;
        for(int i = 0 ; i<basket1.size() ; i++){
            if(basket1[i]!=basket2[i]) {
                flag=1;
                break;
            }
          
        }
        if(flag==0) return 0;
        unordered_map<int,int> mpp1;
        unordered_map<int,int> mpp2;
        set<int> check;

        for(int i = 0 ; i<basket1.size() ; i++){
            mpp1[basket1[i]]++;
            mpp2[basket2[i]]++;
            check.insert(basket1[i]);
            check.insert(basket2[i]);
        }

        for(auto it : check){
            long long s=0;
            if(mpp1.find(it)!=mpp1.end()) s+=mpp1[it];
            if(mpp2.find(it)!=mpp2.end()) s+=mpp2[it];
            if(s%2==1) return -1;
        }

        vector<int> b1;
        vector<int> b2;
     

        for(auto it : check){
            long long cnt1=0;
            long long cnt2=0;
      
            if(mpp1.find(it)!=mpp1.end()) cnt1=mpp1[it];
            if(mpp2.find(it)!=mpp2.end()) cnt2=mpp2[it];

            if(cnt1>cnt2){
                long long mov =abs(cnt1-cnt2);
                mov = mov/2;
           
                while(mov>0){
                    b1.push_back(it);
                    mov--;
                }
            }
            else if(cnt2>cnt1){
                long long mov =abs(cnt1-cnt2);
                mov = mov/2;
               
                while(mov>0){
                    b2.push_back(it);
                    mov--;
                }
            }
            
            
        }
        long long ans = 0;
        sort(b1.begin(),b1.end());
        sort(b2.rbegin(),b2.rend());
        long long mini = min(basket1[0],basket2[0]);
        for(int i = 0 ; i<b1.size() ; i++){
            ans+= min(2*mini , min(1LL*b1[i] , 1LL*b2[i]));
        }
        return ans;
       

    }
};