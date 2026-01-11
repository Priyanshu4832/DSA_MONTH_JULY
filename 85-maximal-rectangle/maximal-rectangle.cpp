class Solution {
public:

    int func( vector<int>& level){

        int n = level.size();
        stack<int> st1;
        stack<int> st2;
        vector<int> pse(n,-1);
        vector<int> nse(n, -1);

        //previous smaller element 
        for(int i=0 ; i<n ; i++){

            int ht = level[i];

            while(!st1.empty() && level[st1.top()]>=ht) st1.pop();

            if(!st1.empty()) pse[i]=st1.top();
            st1.push(i);
        }


        //next smaller element
        for(int i=n-1 ; i>=0 ; i--){
            int ht = level[i];
            while(!st2.empty() && level[st2.top()]>=ht) st2.pop();

            if(!st2.empty()) nse[i]=st2.top();
            st2.push(i);
        }



        // for(int i = 0 ; i<level.size() ; i++){
        //     cout<<level[i]<<"    ";
        // }
        // cout<<endl;
        // for(int i = 0 ; i<level.size() ; i++){
        //     cout<<pse[i]<<"    ";
        // }
        // cout<<endl;
        // for(int i = 0 ; i<level.size() ; i++){
        //     cout<<nse[i]<<"    ";
        // }
        // cout<<endl;



        // finding max
        int maxi = INT_MIN;
        for(int i = 0 ; i<n ; i++){
            int nsee = nse[i];
            int psee = pse[i];
            if(level[i]==0) continue;
            if(nsee==-1 && psee==-1){
                //cout<<" 1.";
                maxi = max(maxi,n*level[i]);
            }
            else if(psee==-1 ){
                //cout<<"  2.";
                maxi = max(maxi,(nsee)*level[i]);
            }
            else if(nsee==-1 ){
                //cout<<" 3.";
                maxi = max(maxi,(n-(psee+1))*level[i]);
            }
            else{
               // cout<<"  4.";
                maxi = max(maxi,((nsee-1)-(psee+1) + 1)*level[i]);
            }
           

            
           // cout<<maxi<<" ";
           
        }
        return maxi;
        
        
        // cout<<endl;
        // cout<<"-------------------------------------"<<endl;

        // return 2;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        

        int r = matrix.size();
        int c = matrix[0].size();
        int maxi = 0;

        vector<int> level(matrix[0].size(),0);
        for(int i = 0 ; i<r ; i++){
            for(int j = 0 ; j<c ; j++){
                if( matrix[i][j]=='1'){
                    if(level[j]>=1) level[j]+=1;
                    else level[j]=1;
                }
                else level[j]=0;


                
            }
            maxi = max(maxi , func(level)); 
        }

        return maxi;
    }
};