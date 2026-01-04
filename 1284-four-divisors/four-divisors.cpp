class Solution {
public:

    int func(int n){

        int sq = sqrt(n);
        int sum = 0;
        int cnt=0;
        for(int i=2 ; i<=sq ; i++){
            if(n%i==0){

                int div1 = i;
                int div2 = n/i;

                if(div1==div2 && (cnt==1 || cnt==0)){
                    cnt+=1;
                    sum+=div1;
                }
                else if(div1!=div2 && cnt==0){
                    cnt+=2;
                    sum+=div1+div2;
                }
                else return -1;

            }
            //cout<<"nums[i] "<<n<<" sum "<<sum<<" i "<<i<<endl;
        }
        if(cnt==2) return sum;

        else return -1;
    }
    int sumFourDivisors(vector<int>& nums) {
        
        int ans = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==1) continue;

            int r = func(nums[i]);
            //cout<<"------------"<<r<<endl;
            if(r!=-1){
                ans+=(r+nums[i]+1);
            }
        }
        return ans;
    }
};