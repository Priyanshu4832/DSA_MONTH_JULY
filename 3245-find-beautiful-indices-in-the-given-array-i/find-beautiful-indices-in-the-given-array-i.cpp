class Solution {
public:

    bool find(int num , int k , vector<int>& arr){

        int low = 0;
        int high = arr.size()-1;

        while(low<=high){
            int mid = low +  (high-low)/2;

            if(  abs(arr[mid]-num)<=k ) return true;
            
            else if(arr[mid]>num){
                high = mid-1;
            }
            else low = mid+1;
        }
        return false;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        
        vector<int> idx1;
        vector<int> idx2;

        for(int i = 0 ; i < s.size() ; i++){

            if(s[i]==a[0] &&   ( i + a.size() -1 ) < s.size()  ){
                
                string check = s.substr(i,a.size());
                if(check==a) idx1.push_back(i);
            }
            if(s[i]==b[0] && ( i + b.size() -1 ) < s.size() ){
                string check = s.substr(i,b.size());
                if(check==b) idx2.push_back(i);
            }
        }


        vector<int> idx;
        for(int i=0 ; i<idx1.size() ; i++){

            if( find(idx1[i] , k, idx2) ) idx.push_back(idx1[i]);
        }
        return idx;
    }
};