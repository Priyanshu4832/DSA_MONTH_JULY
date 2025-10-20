class Solution {
public:
    map<char, int> mpp;

    string func(string &res) {
        for (auto it : mpp) {
            int freq = it.second;
            while (freq > 0) {
                res += it.first;
                freq--;
            }
        }
        return res;
    }

    string lexGreaterPermutation(string s, string target) {
        string res;
        for (auto it : s) mpp[it]++;

        for (int i = 0; i < target.size(); i++) {
            if (mpp.find(target[i]) != mpp.end()) {
                res += target[i];
                mpp[target[i]]--;
                if (mpp[target[i]] == 0) mpp.erase(target[i]);
                continue;
            } 
            else {
                // find greater 
                for (auto it : mpp) {
                    if (it.first > target[i]) {
                        res += it.first;
                        mpp[it.first]--;
                        if (mpp[it.first] == 0) mpp.erase(it.first);

                        return func(res);
                    }
                }
                break;

            }
        }

        while(res.size()>0){
            char prev = res.back();
            res.pop_back();
            mpp[prev]++;

            for (auto it : mpp) {
                if (it.first > prev) {
                    res+=it.first;
                    mpp[it.first]--;
                    if (mpp[it.first] == 0) mpp.erase(it.first);
                    return func(res);

                }
            }

        }


        return "";
    }
};
