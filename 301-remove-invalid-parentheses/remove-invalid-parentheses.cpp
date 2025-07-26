class Solution {
public:

    bool valid(string s){

        int cnt =0 ;
        for(auto i :s){
            if(i=='(') cnt++;
            else if(i==')') cnt--;
            if(cnt<0) return false;
        }
        if(cnt==0) return true;
        return false;
    }

    vector<string> removeInvalidParentheses(string s) {
        
        set<string> vis;
        queue<string> q;
        vector<string> ans;

        q.push(s);
        vis.insert(s);
        bool found = false;

        while(!q.empty()){

            string check = q.front();
            q.pop();
            

            if(valid(check)){
                found = true;
                ans.push_back(check);
            }
            if(found) continue;

            for(int i=0 ; i<check.size() ; i++){
                if(check[i]>='a' && check[i]<='z') continue;

                string ch = check;
                string new_check = ch.erase(i,1);
                cout<<"before and after"<<check<<" "<<new_check<<" delete "<<endl;
                if(vis.find(new_check)==vis.end()){
                    vis.insert(new_check);
                    q.push(new_check);
                }
            }
        }

        if(ans.size()==0) return {""};
        return ans;


    }
};