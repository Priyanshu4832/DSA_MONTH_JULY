class Solution {
public:

    int func(vector<int>& potions , double need){

        int low = 0;
        int high = potions.size()-1;

        while(low<=high){
            int mid = low + (high - low) / 2;
            //cout<<"before"<<endl;
            //cout<<"low mid high "<<low<<" "<<mid<<" "<<high<<endl;
            if(potions[mid]<need){
                low=mid+1;
            }
            else high=mid-1;
            //cout<<"low mid high "<<low<<" "<<mid<<" "<<high<<endl;
        }
        //cout<<"returned low "<<low<<endl;
        return low;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int m = potions.size();
        sort(potions.begin(),potions.end());

        vector<int> successful(spells.size(),0);

        for(int i=0 ; i<spells.size() ; i++){
            double need = ((double)success/spells[i]);
            //cout<<need;
            int idx = func(potions,need );
            if(idx<m){
                successful[i]=(m-idx);
            }
        }
        return successful;
    }
};