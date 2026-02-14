class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        
        unordered_map<string,int> mpp;

        for(auto str : words){
            if(str.size()<k) continue;

            string s = str.substr(0,k);
            mpp[s]++;
        }
        int cnt=0;
        for(auto it : mpp){
            if(it.second>=2) cnt++;
        }
        return cnt;
    }
};