class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size()<=1) return s.size();

        int n = s.size();

        unordered_set<char> st;

        int l = 0 ;
        int r = 1;
        int maxLen = 1;

        st.insert(s[0]);
        while(r<n){
            if(st.find(s[r])!=st.end()){
                while(st.find(s[r])!=st.end()){
                    st.erase(s[l]);
                    l++;
                }
            }
            maxLen = max(maxLen,r-l+1);
            st.insert(s[r]);
            r++;
        }
        return maxLen;
    }
};