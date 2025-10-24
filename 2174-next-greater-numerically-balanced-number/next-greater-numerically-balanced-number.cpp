class Solution {
public:


    int nextBeautifulNumber(int n) {
        
        map<int,vector<string>> mpp;
        mpp[1] = {"1"};
        mpp[2] = {"22"};
        mpp[3] = {"122", "333"};
        mpp[4] = {"1333", "4444"};
        mpp[5] = {"14444", "22333", "55555"};
        mpp[6] = {"122333", "155555",  "224444", "666666"};
        mpp[7] = {"1224444","1666666",  "2255555", "3334444", "7777777"};


        int nDigit = 0;
        int nCopy = n;
        while(nCopy>0){
            nDigit++;
            nCopy/=10;
        }

        int mini=1e8;
        for(auto it : mpp[nDigit]){
            string s = it;
            int ch=stoi(s);
            if(ch>n) mini=min(mini,ch);
            while (next_permutation(s.begin(), s.end())) {
                int num = stoi(s);
                if(num>n) mini=min(mini,num);
            }
        }
        if(mini!=1e8) return mini;
        
        int num = stoi(mpp[nDigit+1][0]);
        return num;

        



    }
};