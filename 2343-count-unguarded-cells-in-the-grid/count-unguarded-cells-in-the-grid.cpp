class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> mat(m, vector<int>(n, 0));
        set<pair<int,int>> st;

        // mark walls
        for (auto &it : walls) {
            mat[it[0]][it[1]] = 1;
            st.insert({it[0], it[1]});
        }

        // mark guards
        for (auto &it : guards) {
            mat[it[0]][it[1]] = 2;
            st.insert({it[0], it[1]});
        }

        // mark guarded cells
        for (auto &it : guards) {
            int r = it[0], c = it[1];

            // up
            for (int nr = r - 1; nr >= 0 && mat[nr][c] != 1 && mat[nr][c] != 2; nr--) {
                if (mat[nr][c] == 0) {
                    mat[nr][c] = 3;
                    st.insert({nr, c});
                }
            }

            // down
            for (int nr = r + 1; nr < m && mat[nr][c] != 1 && mat[nr][c] != 2; nr++) {
                if (mat[nr][c] == 0) {
                    mat[nr][c] = 3;
                    st.insert({nr, c});
                }
            }

            // right
            for (int nc = c + 1; nc < n && mat[r][nc] != 1 && mat[r][nc] != 2; nc++) {
                if (mat[r][nc] == 0) {
                    mat[r][nc] = 3;
                    st.insert({r, nc});
                }
            }

            // left
            for (int nc = c - 1; nc >= 0 && mat[r][nc] != 1 && mat[r][nc] != 2; nc--) {
                if (mat[r][nc] == 0) {
                    mat[r][nc] = 3;
                    st.insert({r, nc});
                }
            }
        }

        // total cells minus occupied or guarded
        return m * n - st.size();
    
        
    }
};