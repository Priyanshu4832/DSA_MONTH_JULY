class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        sort(happiness.begin(), happiness.end());

        int n = happiness.size();
        int timer = -k+1;
        for (int i = n - k; i < n; i++) {
            ans += max(happiness[i] + timer, 0);
            timer += 1;
        }
        return ans;
    }
};