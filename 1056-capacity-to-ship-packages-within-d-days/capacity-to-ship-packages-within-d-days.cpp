class Solution {
public:
    int ship(int weight , vector<int>& weights, int days){

        int cnt = 1 ;
        int sum = 0;
        for(int i=0 ; i<weights.size() ; i++){
            if(weights[i]>weight) return false;
            else if( (sum+weights[i]) >weight ){
                sum = weights[i];
                cnt+=1;
            }
            else sum+=weights[i];
        }
        if(cnt<=days) return true;
        else return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        

        int low=INT_MAX;
        int high = 0;
        for(int i = 0 ; i<weights.size() ; i++){
            low = min(weights[i],low);
            high += weights[i];
        }

        int ans = high;
        while(low<=high){
            int mid = (high+low)/2;

            if(ship(mid,weights,days)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};