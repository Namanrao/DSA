class Solution {
public:
    vector<int> pse(vector<int> &heights){
        int n = heights.size();
        vector<int> prev(n);
        stack<int> st;

        for(int i =0 ;i<n ;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                prev[i] = -1;
            }else{
                prev[i] = st.top();
            }
            st.push(i);
        }
        return prev;
    }
    vector<int> nse(vector<int> &heights){
        int n = heights.size();
        vector<int> next(n);
        stack<int> st;

        for(int i = n-1; i>=0 ;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                next[i] = n;
            }else{
                next[i]=st.top();
            }
            st.push(i);
        }
        return next;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev = pse(heights);
        vector<int> next = nse(heights);
        int max_area =0;
        int n = heights.size();
        for(int i=0; i<n ;i++){
            max_area = max(max_area,(next[i]-prev[i]-1)*heights[i]);
        }
        return max_area;
    }
};