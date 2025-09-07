class Solution {
public:

    long long bowlSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> nextGreater(n);
        vector<int> prevGreater(n);
        
        stack<int> st;

        for(int i = n-1  ; i>=0 ; i--){
            while( !st.empty() && nums[i] > nums[st.top()] ){
                    st.pop();
            }
            if(!st.empty()){
                nextGreater[i]=st.top();
                st.push(i);
            }
            else{
                st.push(i);
                nextGreater[i]=n;
            }
        }
        while(!st.empty()) st.pop();

        for(int i = 0 ; i<n ; i++){
            while(!st.empty() && nums[i] > nums[st.top()] ){
                    st.pop();
            }
            if(!st.empty()){
                prevGreater[i]=st.top();
                st.push(i);
            }
            else{
                st.push(i);
                prevGreater[i]=-1;
            }
        }


        long long cnt = 0 ;

        for(int i=1 ; i<n-1 ; i++){
            if(prevGreater[i]!=-1 && nextGreater[i]!=n) cnt++;
        }

        return cnt;

        
    }
};