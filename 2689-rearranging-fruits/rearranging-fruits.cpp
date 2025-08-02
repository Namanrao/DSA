class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;
        for (int i : basket1) {
            mp[i]++;
        }
        for (int i : basket2) {
            mp[i] -= 1;
        }

        vector<int> extra;
        int minimum_element = INT_MAX;

        for (auto [e, f] : mp) {
            if (f % 2 != 0) {
                return -1;
            }
            int n = abs(f) / 2;
            for (int i = 0; i < n; i++) {
                extra.push_back(e);
            }
            minimum_element = min(minimum_element, e);
        }

        sort(extra.begin(), extra.end());
        long long result = 0;
        for (int i = 0; i < extra.size() / 2; i++) {
            result += min(extra[i], minimum_element * 2);
        }

        return result;
    }
};
