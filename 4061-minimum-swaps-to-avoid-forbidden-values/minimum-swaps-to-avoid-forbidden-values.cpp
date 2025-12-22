class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        

        map<int,int> numsFreq , forbiddenFreq , matching ;

        int maxi = 0;
        int cnt = 0;

        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]==forbidden[i]){
                cnt+=1;
                matching[nums[i]]++;
                maxi = max(maxi ,matching[nums[i]] );
            }
            numsFreq[nums[i]]++;
            forbiddenFreq[forbidden[i]]++;
        }

        for(auto it : numsFreq){
            if(it.second > nums.size() - forbiddenFreq[it.first]) return -1;
        }

        return max( (cnt+1)/2 , maxi );
    }
};
