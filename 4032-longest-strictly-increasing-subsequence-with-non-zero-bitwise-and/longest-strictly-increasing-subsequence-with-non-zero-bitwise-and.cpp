class Solution {
public:

    int lis(vector<int>& arr){

        vector<int> tail;
        for(auto num : arr){
            auto it = lower_bound(tail.begin(),tail.end(),num);

            if(it==tail.end()){
                tail.push_back(num);
            }
            else *it=num;

        }
        return tail.size();
    }
    int longestSubsequence(vector<int>& nums) {
        
        int maxi=0;
        for(int i=0 ; i<=30 ; i++){
            vector<int> temp;
            for(auto it : nums){

                if( (it&(1<<i) ) !=0) temp.push_back(it);
            }
            maxi = max(maxi,lis(temp));
        }
        return maxi;
    }
};