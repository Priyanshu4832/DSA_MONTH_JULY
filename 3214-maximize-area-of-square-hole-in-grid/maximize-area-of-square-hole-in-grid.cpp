class Solution {
public:

    int maxGap(vector<int>& arr){

        
        int maxi = 2;
        for(int i = 0 ; i<arr.size()-1 ; i++){
            if(arr[i]+1==arr[i+1]){
                int cnt =1 ;
                while( i<arr.size()-1 &&  (arr[i]+1 == arr[i+1])){
                    cnt+=1;
                    i++;
                }
                
                maxi = max(cnt+1,maxi);
            }
        }
        return maxi;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int a = maxGap(hBars);
        int b = maxGap(vBars);
        int c = min(a,b);
        return c*c;
    }
};