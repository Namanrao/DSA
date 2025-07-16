class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int arr[26] = {0};
                for (int a = i; a <= j; a++) {
                    int c = s[a] - 'a';
                    arr[c]++;
                }
                int maxFreq = *max_element(arr, arr + 26);
                int minFreq = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (arr[k] > 0) {
                        minFreq = min(minFreq, arr[k]);
                    }
                }
                cnt += maxFreq - minFreq;
            }
        }
        return cnt;
    }
};
