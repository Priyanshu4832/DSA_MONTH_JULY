class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        
        map<int , int> mpp;

        int l = 0 ;
        int r = 0 ;
        int n = arrivals.size();
        set<int> st;
        int cnt=0;


        while(r<n){

            
            mpp[arrivals[r]]++;

            if( (r-l+1) > w  ){
                if(st.find(l)!=st.end()){
                    l++;
                }
                else{
                    mpp[arrivals[l]]--;
                    if(mpp[arrivals[l]]==0) mpp.erase(arrivals[l]);
                    l++;
                }
                

            }

            int freq = mpp[arrivals[r]];

            if(freq>m){
                cnt++;
                st.insert(r);
               
                mpp[arrivals[r]]--;
                
                if(mpp[arrivals[r]]==0) mpp.erase(arrivals[r]);


                if(st.find(l)!=st.end() ){
                    if( (r-l+1) > w ) l++;
                   
                }
                else{
                    
                    
                    if( (r-l+1) > w ) {
                        mpp[arrivals[l]]--;
                        if(mpp[arrivals[l]]==0) mpp.erase(arrivals[l]);
                        l++;
                    }
                }
                
                
            }
            r++;
        }
        return cnt;
    }
};