class Solution {
public:
    int characterReplacement(string s, int k) {
        

        //keep count 
        // r-l+1 -> lenght
        // set size unique character

        int l = 0 ;
        int r = 0;
        int maxLen = 1;
        
        map<char,int> mpp;
        
       
        int maxFreq = 0;
        while(r<s.size()){
          
            mpp[s[r]]++;
            for(auto it : mpp) maxFreq = max(maxFreq , it.second);


            while( (r-l+1)-maxFreq   > k ){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;

                for(auto it : mpp) maxFreq = max(maxFreq , it.second);

            }
        

            maxLen = max(maxLen , r-l+1);
            r++;
            
        }
        return maxLen;
    }
};