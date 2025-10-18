class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        
        
        sort(nums.begin(),nums.end());
        map<int,int,greater<int>>mpp;

        for(int i=0 ; i<nums.size() ; i++) mpp[nums[i]]++;
      

        if(k==0) return mpp.size();
        int myK=k;
        int cnt=0;
        long prev=-1e12;
        
        for(auto num : mpp){
            if(prev!=-1){
                myK=prev-num.first-1;
                myK=min(myK,k);
            }
            
            if(num.second!=1){
                int r=num.second;
                while(myK>=-k && r>0){
                    if(num.first+myK == prev && prev!=-1e12 ){
                        prev=num.first+myK;
                        myK--;
                        
                        

                    }
                    if(myK<-k) break;
                    cnt++;
                    prev=num.first+myK;
                    r--;
                }
                
                
            }
           
            else if(num.second==1){
                cnt++;
                prev = num.first+myK; 
            }
            
            
        }
        return cnt;
    }
};