class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char , int> hash;
        for(int i=0 ; i<t.size() ; i++) hash[t[i]]++;

        int l = 0;
        int r = 0;
        int startIdx = -1;
        int minLen=1e9;
        int cnt =0;

        while(r<s.size()){

            //char is availabe in my hash so decrease its freqncy cnt will increase only when its freq is more than 0 

            // if freq is negative that means we are finding extra of those and in our current window required amount i already there 
            if(hash.find(s[r])!=hash.end()){
                if(hash[s[r]]>0){
                    cnt+=1;
                }
                hash[s[r]]--;

                //when cnt == required now shrink the window 
                

                while(cnt==t.size()){
                    //update lenght and starting idx
                    if(r-l+1<minLen){
                        startIdx = l;
                        minLen = r-l+1;
                    }
                    // cnt will dcrease only when its freq goes above 0 that means our current windoes does not have sufficent amount of that character
                    if(hash.find(s[l])!=hash.end()){
                        hash[s[l]]++;
                        if(hash[s[l]]>0) cnt--;
                        
                        
                    }
                    l++;
                }
               
                
            }
            r++;

            
        }
        if(startIdx==-1) return "";
        string ans = s.substr(startIdx , minLen);
        return ans;

    }
};