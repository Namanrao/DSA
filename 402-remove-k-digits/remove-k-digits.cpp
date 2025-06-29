class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size();
        stack<char> st;
        int counter = 0;
        string result = "";

        if (n == k) {
            return "0";
        }

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() > nums[i] && counter < k) {
                st.pop();
                counter++;
            }
            st.push(nums[i]);
        }

        // If we haven't removed k digits yet, remove from the end
        while (counter < k) {
            st.pop();
            counter++;
        }

        // Build the result from the stack
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        // Remove leading zeros
        int i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }

        result = result.substr(i);

        return result.empty() ? "0" : result;
    }
};
