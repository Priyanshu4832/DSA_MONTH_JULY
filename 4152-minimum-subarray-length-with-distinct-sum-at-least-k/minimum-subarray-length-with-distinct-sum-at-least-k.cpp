class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        
        int n = nums.size();
        int minLen = n;
        bool flag=0;

        int l=0;
        int r=0;
        int sum = 0;

        unordered_map<int,int> mpp;

        while( r  < nums.size()){

            if(mpp.find(nums[r])==mpp.end()) sum+=nums[r];
            mpp[nums[r]]++;

            if(sum>=k){
                flag=1;
                //minLen = min(minLen , r-l+1);
                while(sum>=k){
                    minLen = min(minLen , r-l+1);
                    int num = nums[l];
                    if(mpp[num]>1){
                        mpp[num]--;
                    }
                    else{
                        mpp.erase(num);
                        sum-=num;
                    }
                    l++;

                }
            }
            r++;
        }

        if(flag) return minLen;
        else return -1;

    }
};