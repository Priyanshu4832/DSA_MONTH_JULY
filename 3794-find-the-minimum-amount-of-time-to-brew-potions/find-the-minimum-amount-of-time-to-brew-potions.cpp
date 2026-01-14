class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        

        vector<long long> upperRow={0} ;
        if(skill.size()==1 ){
            long long ans = 0;
            for(int i=0 ; i<mana.size() ; i++) ans+=(1LL*mana[i]*skill[0]);
        }
        long long ans =0;
        for(int i=0 ; i<skill.size() ; i++){
            long long temp = (1LL*mana[0]*skill[i]);
            ans+=temp;
            //cout<<"-"<<ans<<endl;
            upperRow.push_back(ans);
        }
        if(mana.size()==1 ) return ans; 
        



        ans = 0;
        for(int i=1 ; i<mana.size() ; i++){

            vector<long long> bottomRow = {0};
            long long sum = 0;

            for(int j = 0 ; j<skill.size() ; j++){
                sum += 1LL*mana[i]*skill[j];
                bottomRow.push_back(sum);
            }

            long long add=0;
            for(int k = 0 ; k<upperRow.size()-1 ; k++){
                if( (bottomRow[k]+add) < upperRow[k+1] ){
                    add += upperRow[k+1] - (bottomRow[k]+add) ;
                    //cout<<add<<" add"<<endl;
                }
            }
            int n = bottomRow.size();
           
            
            for(int l = 0 ; l<n ; l++){
                bottomRow[l] = bottomRow[l]+add;
            }
            ans = bottomRow[n-1];

            // cout<<"upper row "<<endl;
            // for(int l = 0 ; l<n ; l++){
            //     cout<<upperRow[l]<<" ";
            // }
            // cout<<endl;
            // cout<<"bottom row "<<endl;
            // for(int l = 0 ; l<n ; l++){
            //     cout<<bottomRow[l]<<" ";
            // }
            upperRow = bottomRow;
            // cout<<endl;
            // cout<<endl;
            // cout<<endl;
        }
        return ans;
    }
};