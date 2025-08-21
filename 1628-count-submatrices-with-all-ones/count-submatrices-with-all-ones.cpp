class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        

        int n = mat.size(), m = mat[0].size();
        vector<int> heights(m, 0);
        int ans = 0;

        for (int r = 0; r < n; r++) {
          
            for (int c = 0; c < m; c++) {
                if (mat[r][c] == 0) heights[c] = 0;
                else heights[c] += 1;
            }

            stack<vector<int>> st;
            //{index j of prev shorter , count , height of j}
            st.push({-1,0,-1});

            for(int i = 0 ; i<m ; i++){
                int h = heights[i];
                while(st.top()[2]>=h){
                    st.pop();
                }

                auto top = st.top();
                int j = top[0];
                int prev = top[1];
                int curr = prev + (i-j)*h;
                st.push({i,curr,h});
                ans+=curr; 
            }

           
        }

        return ans;
    }
};