class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        vector<long long> left(3*n,0),right(3*n,0);

        priority_queue<int> maxheap;
        priority_queue<int,vector<int>,greater<int>> minheap;


        long long sum =0 ;
        for(int i=0 ; i<2*n ; i++){
            sum += nums[i];

            maxheap.push(nums[i]);
            if(maxheap.size()>n){
                sum-=maxheap.top();
                maxheap.pop();
            }
            if(maxheap.size()==n) left[i]=sum;
        }
        sum = 0;
        for(int i=3*n-1 ; i>=n ; i--){
            sum += nums[i];

            minheap.push(nums[i]);
            if(minheap.size()>n){
                sum-=minheap.top();
                minheap.pop();
            }
            if(minheap.size()==n) right[i]=sum;
        }

        long long res=LLONG_MAX;
        for(int i= n-1 ; i<2*n ; i++){
            long long val = left[i]-right[i+1];
            res = min(res, val);
        } 
        return res;

    }
};