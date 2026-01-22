class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        vector<int> mark(n, 0);

        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(') {
                st.push(i);
            } else if (c == ')') {
                if (st.empty()) {
                    mark[i] = 1;  // unmatched ')'
                } else {
                    st.pop();    // matched ')'
                }
            }
            // all other characters are ignored
        }

        // unmatched '('
        while (!st.empty()) {
            mark[st.top()] = 1;
            st.pop();
        }

        string result;
        result.reserve(n); // small optimization
        for (int i = 0; i < n; i++) {
            if (!mark[i]) {
                result += s[i];
            }
        }

        return result;
    }
};
