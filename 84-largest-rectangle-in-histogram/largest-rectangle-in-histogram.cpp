class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        // stack<int> st;
        // int area=0;


        // for(int i=0 ; i<heights.size() ; i++){

        //     while(!st.empty() && heights[st.top()]>heights[i]){
        //         int element=st.top();
        //         st.pop();
        //         int nse=i;
        //         int pse=st.empty() ? -1 : st.top();
        //         area=max(area, ( heights[element] * (nse-pse-1) ) );
        //     }
        //     st.push(i);
        // }

        // while(!st.empty()){
        //     int nse=heights.size();
            
        //     int element=st.top();
        //     st.pop();
        //     int pse=st.empty() ? -1 : st.top();
        //     area=max(area, ( heights[element] * (nse-pse-1) ) );
        // }
        // return area;

        int n = heights.size();
        vector<int> pse(n);
        vector<int> nse(n);
        stack<int> st;

        for(int i = 0 ; i<n ; i++){

            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }

            if(!st.empty()){
                pse[i]=st.top();
            }
            else{
                pse[i]=-1;
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i = n-1 ; i>=0 ; i--){

            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }

            if(!st.empty()){
                nse[i]=st.top();
            }
            else{
                nse[i]=n;
            }
            st.push(i);
        }

        int area = 0;
        for(int i=0 ; i<n ; i++){
            area = max(area , heights[i]*(nse[i]-pse[i]-1));
        }
        return area;
    }
};