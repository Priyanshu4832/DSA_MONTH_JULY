class Solution {
public:
    int numSub(string s) {
        
        int i=0 ;
        int mod = 1000000007;
        
        int cnt=0;
        while(i<s.size()){
            if(s[i]=='1'){
                cnt = (cnt+1)%mod;
                int c=i;
                i+=1;
                while(i<s.size() && s[i]=='1'){
                    cnt=(i-c+1 + cnt)%mod;
                    i++;
                }
            }
            else i++;
        }
        return cnt;
    }
};