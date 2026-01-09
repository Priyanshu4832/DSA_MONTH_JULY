class Solution {
public:
    using state = tuple<int, int, int, int>;

    // Helper to check if two directions are opposites
    // 1: Right, 2: Left, 3: Down, 4: Up
    bool isOpposite(int d1, int d2) {
        if (d1 == 1 && d2 == 2) return true;
        if (d1 == 2 && d2 == 1) return true;
        if (d1 == 3 && d2 == 4) return true;
        if (d1 == 4 && d2 == 3) return true;
        return false;
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Min-priority queue based on cost
        priority_queue<state, vector<state>, greater<state>> pq;

        // vis[r][c][dir]
        vector<vector<vector<int>>> vis(m, vector<vector<int>>(n, vector<int>(5, 0)));

        // Initial state: cost 0, start (0,0), dummy direction 0 (so no opposite is blocked)
        pq.push({0, 0, 0, 0});

        while (!pq.empty()) {
            auto [cost, r, c, direction] = pq.top();
            pq.pop();

            if (r == m - 1 && c == n - 1) return cost;
            
            if (vis[r][c][direction]) continue;
            vis[r][c][direction] = 1;

            // 1. Handle Following the Grid (Cost 0)
            int go = grid[r][c];
            // Only follow the grid if it doesn't take us directly back
            if (!isOpposite(direction, go)) {
                int nr = r, nc = c;
                if (go == 1) nc = c + 1;
                else if (go == 2) nc = c - 1;
                else if (go == 3) nr = r + 1;
                else if (go == 4) nr = r - 1;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc][go] == 0) {
                    pq.push({cost, nr, nc, go});
                }
            }

            // 2. Handle Modifying the Grid (Cost 1)
            for (int i = 1; i <= 4; i++) {
                // Skip if this was the direction we handled for cost 0
                if (i == go) continue;

                // Skip if this direction is the opposite of where we came from
                if (!isOpposite(direction, i)) {
                    int nr = r, nc = c;
                    if (i == 1) nc = c + 1;      // Right
                    else if (i == 2) nc = c - 1; // Left
                    else if (i == 3) nr = r + 1; // Down
                    else if (i == 4) nr = r - 1; // Up

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc][i] == 0) {
                        pq.push({cost + 1, nr, nc, i});
                    }
                }
            }
        }
        return 0;
    }
};