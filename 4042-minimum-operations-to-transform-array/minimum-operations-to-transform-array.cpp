class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        
        long long cnt=1;
        long long k = nums2[nums2.size()-1];
        long long distance=1e7;

        for(int i=0 ; i<nums1.size() ; i++){
            long long mini = min(nums1[i],nums2[i]);
            long long maxi = max(nums1[i],nums2[i]);

            long long dist = abs(nums1[i]-nums2[i]);
            cnt+=dist;
           
            if(k>=mini && k<=maxi) distance = 0;
            
            else if(k<mini) distance = min(distance,mini-k);
            else if(k>maxi) distance = min(distance , k-maxi);
        }

        cnt+=distance;
        return cnt;
    }
};