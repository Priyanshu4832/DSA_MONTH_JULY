
class Solution {
public:
    long long dfs(int pos, int tight, int ones, set<int>& valid,string& s, vector<vector<vector<long long>>>& dp) {
        if (pos == s.size()) {
            if(valid.find(ones)!=valid.end()) return 1;
            else return 0;
        }
        if (dp[pos][tight][ones] != -1) {
            return dp[pos][tight][ones];
        }
        int limit = tight ? (s[pos] - '0') : 1;
        long long res = 0;
        for (int i = 0; i <= limit; ++i) {
            int new_tight = tight && (i == limit);
            int new_ones = ones + i;
            res += dfs(pos + 1, new_tight, new_ones, valid, s, dp);
        }
        return dp[pos][tight][ones] = res;
    }

    long long popcountDepth(long long n, int k) {
        if (n == 0) return 0;
        if (k == 0) return n >= 1 ? 1 : 0;

        set<int> valid;
        for (int i = 1; i <= 64; ++i) {
            int depth = 0;
            int x = i;
            while (x > 1) {
                x = __builtin_popcount(x);
                depth++;
            }
            if (depth == k - 1) {
                valid.insert(i);
            }
        }

        if (valid.empty()) {
            return 0;
        }

        string s;
        long long a = n;
        while (a > 0) {
            s += (a % 2) + '0';
            a /= 2;
        }
        reverse(s.begin(), s.end());

        int len = s.size();
        vector<vector<vector<long long>>> dp(len, vector<vector<long long>>(2, vector<long long>(65, -1)));

        //dp[pos][tight][count ones]
        long long result = dfs(0, 1, 0, valid, s, dp);

        if (k == 1) {
            result -= 1;
        }
        return result;
    }
};