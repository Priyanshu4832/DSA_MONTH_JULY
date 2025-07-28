class Solution {
public:

    void func(int idx , int curr_or , vector<int>& nums, unordered_map<int,int>& freq ){
        if(idx==nums.size()){
            freq[curr_or]++;
            return;
        }

        //pick
        func(idx+1 , (curr_or | nums[idx]) ,nums ,freq );
        func(idx+1 , curr_or , nums , freq);
        return;

    }
    int countMaxOrSubsets(vector<int>& nums) {
        
        unordered_map<int,int> freq;
        func(0,0,nums,freq);

        int maxi=0;
        int cnt =0;
        for(auto it : freq){
            if(it.first>maxi){
                maxi=it.first;
                cnt=it.second;
            }
        }
        return cnt;
    }
};