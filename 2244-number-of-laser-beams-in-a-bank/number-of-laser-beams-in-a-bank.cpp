class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int rows = bank.size();
        int columns = bank[0].size();
        vector<int> count_rows(rows);

        // Count all the '1's in each row
        for (int i = 0; i < rows; i++) {
            int ones = 0;
            for (int j = 0; j < columns; j++) {
                if (bank[i][j] == '1') {
                    ones++;
                }
            }
            count_rows[i] = ones;
        }

        // Calculate total beams
        int ans = 0;
        int prev = 0;

        for (int i = 0; i < rows; i++) {
            if (count_rows[i] > 0) {
                ans += prev * count_rows[i];
                prev = count_rows[i];
            }
        }

        return ans;
    }
};
