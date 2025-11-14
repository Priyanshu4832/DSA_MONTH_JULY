class Solution {
public:

    int maxOperations(string s) {
        

        int n = s.size();
        int cnt=0;
        int accOnes=0;

        int i=0;
       
        while(i<n){

            if(s[i]=='1'){
                int c=0;
                while(i<n && s[i]=='1'){
                    c++;
                    i++;
                }
                cnt+=accOnes;
                accOnes+=c;
             
                

            }
            if(i==n-1) cnt+=accOnes;
            i++;
            
        }
        return cnt;
    }
};