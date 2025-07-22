class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        int res = 0;
        
        int sum = 0 ;
        int l = 0;
        int r = 0;

        unordered_set<int> st;
        while(r<nums.size()){

            if(st.find(nums[r])==st.end()){
                sum+=nums[r];
                st.insert(nums[r]);
                res = max(sum,res);
            }
            else{
                while(st.find(nums[r])!=st.end()){
                    sum-=nums[l];
                    st.erase(nums[l]);
                    l++;
                }
                sum+=nums[r];
                st.insert(nums[r]);
            }
            r++;

        }
        return res;
    }
};