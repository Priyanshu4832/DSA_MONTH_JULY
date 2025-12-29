class Solution {
public:
    bool func(int idx1, int idx2, string down, string up,
              vector<vector<vector<string>>>& lookup) {


        if (up.size() == 1 && up[0] != 'X') return true;

        if (idx2  == up.size()) {
            // create new top and bottom
            int len = up.size() - 1;
            string s;
            for(int i=0 ; i<len ; i++) s+="X";
            return func(0, 0, up,s,lookup);
        }

        if(idx1 >= down.size() - 1) return false;
        // try out all possible ways
        int c1 = down[idx1] - 'A';
        int c2 = down[idx1+1] - 'A';
        for (auto s : lookup[c1][c2]) {

            up[idx2] = s[2];
            if(func(idx1 + 1, idx2 + 1, down, up, lookup) == true) return true;
             
        }

        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {

        vector<vector<vector<string>>> lookup(7, vector<vector<string>>(7));

        for (auto it : allowed) {
            int c1 = it[0] - 'A';
            int c2 = it[1] - 'A';
            lookup[c1][c2].push_back(it);
        }

        int len = bottom.size() - 1;
        string s;
        for(int i=0 ; i<len ; i++) s+="X";
        return func(0,0,bottom , s , lookup);
    }
};