class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        int total_y = 0, total_n = 0;
        for (char c : customers) {
            if (c == 'Y') total_y++;
            else total_n++;
        }

        // previous_n[i] = number of 'N' in [0, i)
        // forward_y[i]  = number of 'Y' in [i, n)
        vector<int> previous_n;
        vector<int> forward_y;

        forward_y.push_back(total_y); // closing at 0

        int y = 0, m = 0;
        for (int i = 0; i < n; i++) {
            previous_n.push_back(m);

            if (customers[i] == 'Y') {
                forward_y.push_back(total_y - y - 1);
                y++;
            } else {
                forward_y.push_back(total_y - y);
                m++;
            }
        }

        previous_n.push_back(total_n); // closing at n

        int min_penalty = total_y; // closing at 0
        int result = 0;

        // evaluate closing times 0..n-1
        for (int i = 0; i < n; i++) {
            int penalty = previous_n[i] + forward_y[i];
            if (penalty < min_penalty) {
                min_penalty = penalty;
                result = i;
            }
        }

        // evaluate closing at n (open all day)
        int penalty_all_open = total_n;
        if (penalty_all_open < min_penalty) {
            result = n;
        }

        return result;
    }
};
