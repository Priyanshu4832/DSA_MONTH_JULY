class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        vector<int> dup;
        for (int i=0 ; i<nums.size() ; i++) {
            freq[nums[i]]++;
            if ( freq[nums[i]] >= 2) dup.push_back(nums[i]);
        }

        

        int k = 0;
        if (dup.size() == 0) return k;
        //cout << *nums.begin()<<" " ;
       
       int i=0;
       int q=0;
        while (q <dup.size() && nums.size() >= 3) {
            freq[nums[i]]--;
            freq[nums[i+1]]--;
            freq[nums[i+2]]--;
            
            while (q <dup.size()  && freq[dup[q]] <= 1 ) {
                q++;
                //cout << 5 << endl;
            }
            i+=3;
            k++;
        }
        //for ( int i : nums) cout << i << endl;
        if (dup.size() == q) return k;
        // cout << dup[0] << " " <<freq[dup[0]]<< endl;
        return k+1;

    }
};