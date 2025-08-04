class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        

        int l = 0 ;
        int r = 0 ;

        map<int,int> mpp;
        //fruit , freq


        int maxi = 0;
        int cnt = 0 ;
        while(r<fruits.size()){

            mpp[fruits[r]]++;
            cnt+=1;

            while(mpp.size()>2){
                cnt-=1;
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }

            maxi = max(maxi,cnt);
            r++;

        }
        return maxi;

    }
};