class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<pair<int,int>> st;
        int n = temperatures.size();


        vector<int> days(n,0);
        for(int i=n-1 ; i>=0 ; i--){

            if(st.empty()){
                st.push({temperatures[i],i});
                days[i]=0;
            }

            if(st.top().first>temperatures[i]){
                st.push({temperatures[i],i});
                days[i]=1;
            }
            if(st.top().first<=temperatures[i]){
                int cnt=0;
                while(!st.empty() && st.top().first<=temperatures[i] ){
                    cnt++;
                    st.pop();
                }
                if(st.empty()){
                    st.push({temperatures[i],i});
                    days[i]=0;
                }
                else {
                    days[i]=st.top().second - i;
                    st.push({temperatures[i],i});
                   
                }
            }
        }

        return days;
    }
};