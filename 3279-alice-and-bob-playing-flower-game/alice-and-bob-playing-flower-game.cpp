class Solution {
public:
    long long flowerGame(int n, int m) {
        // if n is even  1,2,3,4,5,6
        //odd+odd is even and even + even is even 
        // only odd + even is odd
        //total odd in n and total even in m *2
        long long cnt = 0;
        int oddCnt = ceil(n/2.0);
        int evenCnt = m/2;
        cout<<oddCnt<<" "<<evenCnt<<endl;
        cnt += (1LL*oddCnt*evenCnt);
        oddCnt = ceil(m/2.0);
        evenCnt = n/2;
        cout<<oddCnt<<" "<<evenCnt<<endl;
        cnt += (1LL*oddCnt*evenCnt);
        return cnt;
    }
};