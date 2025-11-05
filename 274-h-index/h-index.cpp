class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        sort(citations.begin() , citations.end());

        int h=0;
        for(int i=0 ; i<citations.size() ; i++){
            int cnt = citations[i];
            int paperCnt = citations.size()-i;

            if(cnt>=paperCnt){
                h=max(h,paperCnt);
            }
        }
        return h;
    }
};