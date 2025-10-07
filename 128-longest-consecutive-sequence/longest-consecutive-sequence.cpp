class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        int maxLen=1;
        unordered_set<int> st;
        for(int i=0 ; i<nums.size() ; i++){
            st.insert(nums[i]);
        }

        for(auto i : st){
            if(st.find(i)!=st.end() && st.find(i+1)==st.end()){
                int cnt=1;
                int start=i-1;
                while(true){
                    if(st.find(start)!=st.end()){
                        cnt++;
                        start--;
                    }
                    else break;
                }
                maxLen = max(maxLen,cnt);
            }
        }


        return maxLen;
    }
};