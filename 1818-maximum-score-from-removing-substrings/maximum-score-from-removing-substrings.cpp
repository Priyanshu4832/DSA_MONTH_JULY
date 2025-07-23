class Solution {
public:

    // ab
    pair<string,int> func1(string s , int point){
        int n = s.size();
        int cnt = 0;
        stack<char> st;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='b' && !st.empty() && st.top()=='a'){
                st.pop();
                cnt+=point;
            }
            else st.push(s[i]);
        }
        string ret ="";
        while(!st.empty()){
            ret+=st.top();
            st.pop();
        }
        reverse(ret.begin(),ret.end());
        return {ret,cnt};
    }
    // ba
    pair<string,int> func2(string s,int point){
        int n = s.size();
        int cnt = 0;
        stack<char> st;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='a' && !st.empty() && st.top()=='b'){
                st.pop();
                cnt+=point;
            }
            else st.push(s[i]);
        }
        string ret ="";
        while(!st.empty()){
            ret+=st.top();
            st.pop();
        }
        reverse(ret.begin(),ret.end());
        return {ret,cnt};
    }
    int maximumGain(string s, int x, int y) {
        
        if(x>=y){
            // first ab then ba
            auto it = func1(s , x);
            auto itt = func2(it.first , y);
            return it.second + itt.second;
        }
        else{
            // first ba then ab
            auto it = func2(s , y);
            auto itt = func1(it.first , x);
            return it.second + itt.second;
        }
    }
};