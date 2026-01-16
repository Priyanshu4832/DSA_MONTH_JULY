class Solution {
public:
    int mod = 1000000007;
    
    unordered_set<long long> gaps(vector<int>& fences ,int maxLimit){

        unordered_set<long long> st;
        long long n  = fences.size();

        for(long long i = 0 ; i<n ; i++){

            long long p = (i==0) ? 1 : fences[i-1];
            long long ne = (i==n-1) ? maxLimit : fences[i+1];
            st.insert(ne-fences[i]);
            st.insert(fences[i]-p);

            for(long long j = i ; j<n ; j++){

                long long prev = (i==0) ? 1 : fences[i-1];
                long long next = (j==n-1) ? maxLimit : fences[j+1];
                st.insert(next-prev); 
            }
        }
        return st;

    }
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        unordered_set<long long > st1 = gaps(hFences,m);
        unordered_set<long long > st2 = gaps(vFences,n);

        int ans = -1;

        long long maxSide = -1;
        for(auto it : st1){
            if(st2.find(it)!=st2.end()){
                maxSide = max(maxSide , it);
            }
        }

        //if(maxSide==-1)
        return (maxSide==-1) ? -1 : (1LL*maxSide*maxSide)%mod;
    }
};