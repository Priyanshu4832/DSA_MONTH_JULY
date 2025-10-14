class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        //direct match
        unordered_set<string> st;
        for(auto it : wordlist) st.insert(it);

        //lower then match 
        unordered_map<string,string>mpp;
        unordered_map<string,string> vow;
        for(auto word : wordlist){
            string str1;
            string str2;
            for(int i = 0 ; i<word.size() ; i++){
                str1+=tolower(word[i]);
                char ch = tolower(word[i]);
                if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                    str2+='*';
                }
                else str2+=ch;

            }
            if(mpp.find(str1)==mpp.end()) mpp[str1]=word;
            if(vow.find(str2)==vow.end()) vow[str2]=word;
        }

        //vowel match

        
        

        vector<string> res;
        for(auto word : queries){

            string str1;
            for(int i = 0 ; i<word.size() ; i++){
                str1+=tolower(word[i]);
            }
            string str2;
            for(int i = 0 ; i<word.size() ; i++){

                char ch = tolower(word[i]);
                if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                    str2+='*';
                }
                else str2+=ch;
            }
            if(st.find(word)!=st.end()) res.push_back(word);

            else if(mpp.find(str1)!=mpp.end()){
                res.push_back(mpp[str1]);

            }
            else if(vow.find(str2)!=vow.end()){
                res.push_back(vow[str2]);
            }
            else res.push_back("");

        }
        return res;

    }
};