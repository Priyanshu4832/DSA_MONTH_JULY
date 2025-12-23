class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        vector<int> dup;
        for ( int i : nums) {
            freq[i]++;
            if ( freq[i] >= 2) dup.push_back(i);
        }

        

        int k = 0;
        if (dup.size() == 0) return k;
        //cout << *nums.begin()<<" " ;
       
       int i=0;
        while (dup.size() > 0 && nums.size() >= 3) {
            freq[nums[i]]--;
            freq[nums[i+1]]--;
            freq[nums[i+2]]--;
            
            while (dup.size() > 0 && freq[dup[0]] <= 1 ) {
                dup.erase(dup.begin());
                //cout << 5 << endl;
            }
            i+=3;
            k++;
        }
        //for ( int i : nums) cout << i << endl;
        if (dup.size() == 0) return k;
        // cout << dup[0] << " " <<freq[dup[0]]<< endl;
        return k+1;

    }
};