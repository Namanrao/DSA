class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int max_time = 0;

        queue<pair<pair<int, int>, int>> q;

        // Push all initially rotten oranges into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }

        // 4-directional traversal arrays
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // BFS traversal
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            max_time = max(max_time, t);

            for (int d = 0; d < 4; d++) {
                int nrow = r + drow[d];
                int ncol = c + dcol[d];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                    grid[nrow][ncol] = 2; // rot it
                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }

        // Check if any fresh orange is left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return max_time;
    }
};
