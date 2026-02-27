class Solution {
public:
    int numSteps(string s) {


        int cnt=0;
        while(s.size()!=1){
            if(s[s.size()-1]=='1'){
              
                bool found = false;
                for(int i=s.size() ; i>=0 ; i--){
                    if(s[i]=='0'){
                        s[i]='1';
                        found = true;
                        break;
                    }
                    else s[i]='0';
                }
                if(found==false){
                    string temp = "1"+s;
                    s=temp;
                }
  
            }
            else{
                string temp = s.substr(0,s.size()-1);
                s=temp;
            }
            cnt+=1;
        }
        return cnt;
    }
};