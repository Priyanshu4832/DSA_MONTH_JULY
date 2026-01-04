class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        
        vector<vector<string>> ans;
        int n = words.size();
        for(int i=0 ; i<n ; i++){
            string top=words[i];

            for(int j=0 ; j<n ; j++){
                if(j==i) continue;
                string left = words[j];

                for(int k=0 ; k<n ; k++){
                    if(j==k || i==k) continue;
                    string right = words[k];

                    for(int l=0 ; l<n ; l++){

                        if(i==l || j==l || k==l) continue;
                        string bottom = words[l];

                        if(top[0] == left[0] && top[3] == right[0] && bottom[0] == left[3] &&bottom[3] == right[3]){
                            ans.push_back({top,left,right,bottom});
                        }

                    }
                }
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};