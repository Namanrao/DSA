class Solution {
public:
    vector<int> nsl(vector<int> &nums){
        // clean code.
        int n = nums.size();
        vector<int> result(n);
        stack<int> st;
        for(int i =0 ;i<n ;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()){
                result[i] = -1;
            }else{
                result[i] =st.top();
            }
            st.push(i);
        }
        return result;
    }
    vector<int> nsr(vector<int> &nums){
        int n = nums.size();
        vector<int> result(n);
        stack<int> st;
        for(int i =n-1; i>=0 ;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.empty()){
                result[i] = n;
            }else{
                result[i] = st.top();
             }
             st.push(i);
        }
        return result;
    }
    int sumSubarrayMins(vector<int>& nums) {
        vector<int> left = nsl(nums);
        vector<int> right = nsr(nums);
        int m = 1e9 + 7;
long long total = 0;

for (int i = 0; i < nums.size(); i++) {
    long long l = i - left[i];
    long long r = right[i] - i;
    long long val = nums[i] % m;

    long long contrib = (val * l) % m;
    contrib = (contrib * r) % m;

    total = (total + contrib) % m;
}
return total;
    }
};