class Solution {
public:
    int func(vector<int> & hash){
        int cnt=0;
        for(int i = 1; i<25 ; i++){
            if(hash[i]==0) continue;
            hash[i+1] += hash[i];
            cnt++;
        }
        cnt++;
        return cnt;
    }
    int minOperations(string s) {
        
        vector<int> hash(26,0);
        for(int i = 0 ; i<s.size() ; i++){
            hash[s[i]-'a']++;
        }

      
        
        for(int i=1 ; i<26 ; i++){
            if(hash[i]!=0){
                return func(hash);
            }
        }
        return 0;
        
    }
};