class Solution {
public:

    int func(vector<int> arr){

        int n=arr.size();
        int left=0;
        int right=2;
        int middle = 1;
        int res=1e9;
        while(right<n){
            res= min(res , abs(arr[left]-arr[middle])+abs(arr[middle]-arr[right])+abs(arr[left]-arr[right]));
            left++;
            right++;
            middle++;
        }
        return res;
    }
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>> mpp;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            mpp[nums[i]].push_back(i);
        }

        int res=1e9;
        for(auto it : mpp){

            if(it.second.size()<3) continue;

            vector<int> check = it.second;
            res = min(res,func(check));
        }
        if(res==1e9) return -1;
        return res;
    }
};