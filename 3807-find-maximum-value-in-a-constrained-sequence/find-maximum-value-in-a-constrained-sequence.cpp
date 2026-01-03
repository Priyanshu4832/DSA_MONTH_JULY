class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        
        vector<int> arr(n,0);
        unordered_map<int,int> mpp;
        for(auto it : restrictions) mpp[it[0]]=it[1];
        
        int i=0;
        int maxi=0;
        while(true){

            if(i==n-1) break;
            int nextIdx = i+1;

            if(mpp.find(nextIdx)!=mpp.end()){
                

                int maxVal = mpp[nextIdx];
                int gap = abs(arr[i]-maxVal);

                if( gap<=diff[i] ){
                    
                    arr[nextIdx]=maxVal;
                }
                else if( gap>diff[i] && maxVal>arr[i]){
                    arr[nextIdx]=arr[i]+diff[i];
                }
                else{
                    // here i need to move back
                    arr[nextIdx]=maxVal;
                    arr[i] = arr[i] - (gap - diff[i]);

                    for(int k = i-1 ; k>=0 ; k--){

                        int temp_gap = abs(arr[k]-arr[k+1]);
                        if( temp_gap>diff[k] ){
                            arr[k] = arr[k] - (temp_gap - diff[k]);
                        }
                        else break;
                    }
                }

                i+=1;

            }
            else{
                arr[nextIdx]=arr[i]+diff[i];
                i+=1;
            }
        }
        for(auto it : arr) maxi=max(maxi,it);
        return maxi;
    }
};