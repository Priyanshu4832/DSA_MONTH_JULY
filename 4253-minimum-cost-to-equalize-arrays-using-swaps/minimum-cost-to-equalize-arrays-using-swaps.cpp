class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int> mpp1;
        map<int,int> mpp2;
        int cost = 0;
        int swap1 = 0;
        int swap2 = 0;

        for(int i=0 ; i<nums1.size() ; i++){
            mpp1[nums1[i]]++;
            mpp2[nums2[i]]++;
        }

        for(auto it : mpp1){

            int val =  it.first;
            //check if its in mpp2;
            if(mpp2.find(val)!=mpp2.end()){
                int tot = it.second + mpp2[val];


                // odd count can never be solve
                if(tot%2!=0) return -1;


                // for even count check if they have same cnt in each then no cose otherwise cost
                if(mpp2[val]!=mpp1[val] ){
                    int mid = tot/2;
                    if(mpp1[val]>mpp2[val]){
                        swap1 += mpp1[val] - mid;
                    }
                    else swap2 += mpp2[val] - mid;
                    mpp1[val]=mid;
                    mpp2[val]=mid;
                }

            }
            else{
                // this number is only in mpp1 therefore move it till mid in other arrray

                if(it.second % 2 !=0) return -1;
                swap1 += it.second/2;
                mpp1[val]=it.second/2;
                mpp2[val]=it.second/2;

            }
        }

        for(auto it : mpp2){
            int val = it.first;
            if(mpp1.find(val)==mpp1.end()){
                if(it.second%2!=0) return -1;
                mpp1[val]=it.second/2;
                mpp2[val]=it.second/2;
                swap2 += it.second/2;

            }
           
            
        }

        cout<<swap1<<"   " << swap2;
        if(mpp1 !=mpp2) return -1;
        return (swap1+swap2)/2;
    }
};