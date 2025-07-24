class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        if(k==1) return nums;
        vector<int> ans;
        priority_queue<pair<int,int>> maxHeap;

        //pre filling
        for(int i =0 ; i<k ; i++) maxHeap.push({nums[i],i});
        ans.push_back(maxHeap.top().first);
        int l = 1;
        int r = k;


        while(r<nums.size()){

            maxHeap.push({nums[r],r});

         
            while( maxHeap.top().second<l  ){
                maxHeap.pop();
            }

            ans.push_back(maxHeap.top().first);




            l++;
            r++;
        }
        return ans;
    }
};