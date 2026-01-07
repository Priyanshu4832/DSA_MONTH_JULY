class Solution {
public:

    int canForm(int mid , vector<int> arr , int m , int k){

        int boq = 0;

        int i = 0;
        while(i<arr.size()){
            if(arr[i]<=mid){
                //cout<<arr[i]<<endl;
                int cnt = 0;
                while(i<arr.size() && arr[i]<=mid){
                    cnt++;
                    i++;
                }
                i--;
                
                boq += (cnt/k);
                //cout<<boq<<endl;
            }
            i++;
        }

        if( boq>=m ) return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        

        int n = bloomDay.size();
        int low = bloomDay[0];
        int high = bloomDay[n-1];
        for(int i = 0 ; i<n ; i++){
            low = min(low , bloomDay[i]);
            high = max(high , bloomDay[i]);
        }
        

        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            //cout<<mid<<endl;
            if(canForm(mid,bloomDay,m,k)){
                ans = mid;
                
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};