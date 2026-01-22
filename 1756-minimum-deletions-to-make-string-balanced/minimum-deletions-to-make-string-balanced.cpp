class Solution {
public:
    int minimumDeletions(string s) {
        
        int cntA=0;
        int cntB=0;
        
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='a') cntA+=1;
        }
        cntB=s.size()-cntA;

        int runningA=0;
        int runningB=0;
        int ans = 1e6;
        for(int i=0 ; i<s.size() ; i++){

            int rightA = cntA-runningA;
            int leftB = runningB;

            //to makr balaneced remove right a and left b
            ans = min(rightA+leftB,ans);
            if(s[i]=='a') runningA+=1;
            else runningB+=1;

        }
        int rightA = cntA-runningA;
        int leftB = runningB;

        //to makr balaneced remove right a and left b
        ans = min(rightA+leftB,ans);
        return ans;

    }
};