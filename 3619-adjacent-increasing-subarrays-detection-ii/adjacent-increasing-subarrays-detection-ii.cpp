class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        int glob=0;
        int k=0;

        int maxLen=0;

        while(k<nums.size()){
            
            //get the increasing sequenece 
            int cnt1=0,cnt2=0;
            //cout<<"element is "<<nums[k]<<" cnt1 "<<cnt1<<" k "<<k<<endl;
            while( k+1<n && nums[k]<nums[k+1]){
                //cout<<"element is "<<nums[k]<<" cnt1 "<<cnt1<<" k "<<k<<endl;
                cnt1++;
                k++;
                //cout<<"element is "<<nums[k]<<" cnt1 "<<cnt1<<" k "<<k<<endl;
                
            }
            cnt1++;
            k++;
            //cout<<"element is "<<nums[k]<<" cnt1 "<<cnt1<<" k "<<k<<endl;

            maxLen=max(maxLen , cnt1/2);
            maxLen=max(min(glob,cnt1) ,maxLen );
            cout<<maxLen<<endl;

            //cout<<"element is "<<nums[k]<<" cnt2 "<<cnt2<<" k "<<k<<endl;
            while( k+1<n && nums[k]<nums[k+1]){
                //cout<<"element is "<<nums[k]<<" cnt2 "<<cnt2<<" k "<<k<<endl;
                cnt2++;
                k++;
                //cout<<"element is "<<nums[k]<<" cnt2 "<<cnt2<<" k "<<k<<endl;
            }
            cnt2++;
            k++;
            //cout<<"eelement is "<<nums[k]<<" cnt2 "<<cnt2<<" k "<<k<<endl;
            maxLen = max(maxLen , cnt2/2);
            maxLen = max(maxLen , min(cnt1,cnt2));
            glob = cnt2;
            cout<<maxLen<<endl;


        }
        return maxLen;
    }
};
