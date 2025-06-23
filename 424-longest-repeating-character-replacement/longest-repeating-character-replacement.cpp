class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int start = 0;
        int result = 0;
        int arr[26] = {0};
        int max_frequency = 0;

        for (int end = 0; end < n; end++) {
            int index = s[end] - 'A';
            arr[index]++;
            
            // update max_frequency
            max_frequency = max(max_frequency, arr[index]);
            
            int window_size = end - start + 1;
            
            if (window_size - max_frequency > k) {
                arr[s[start] - 'A']--;
                start++;
            }
            
            result = max(result, end - start + 1);
        }

        return result;
    }
};
