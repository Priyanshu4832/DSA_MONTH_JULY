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
            if(hash.find(s[r])!=hash.end()){
                if(hash[s[r]]>0){
                    cnt+=1;
                }
                hash[s[r]]--;

                while(cnt==t.size()){
                    if(r-l+1<minLen){
                        startIdx = l;
                        minLen = r-l+1;
                    }
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