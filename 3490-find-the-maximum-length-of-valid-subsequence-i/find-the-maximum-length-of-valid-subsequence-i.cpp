class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        int cnt =0 ;
        int maxi=0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]%2==0) cnt++;
        }
        maxi=max(maxi,cnt);



        cnt=0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]%2==1) cnt++;
        }
        maxi = max(maxi,cnt);


        cnt=0;
        if(nums[0]%2==0){

            cnt++;
            int flag=1;
            for(int i=1 ; i<nums.size() ; i++){
                if(nums[i]%2==1 && flag==1) {
                    cnt++;
                    flag=0;
                }
                else if(nums[i]%2==0 && flag==0){
                    cnt++;
                    flag=1;
                }
            }
        }
        else{
            int flag=0;
            cnt++;
            for(int i=1 ; i<nums.size() ; i++){
                cout<<" flag "<<flag<<" nums[i] "<<nums[i]<<endl;
                if(nums[i]%2==1 && flag==1) {
                    cnt++;
                    flag=0;
                }
                else if(nums[i]%2==0 && flag==0){
                    cnt++;
                    flag=1;
                    cout<<flag<<endl;
                }
            }
          
        }

        maxi=max(maxi,cnt);
        return maxi;
        
    }
};