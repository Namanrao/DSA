class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n,0);
        stack<pair<int,int>> st;
        for(int i = n- 1; i>=0 ; i--){
            if(st.empty()){
                result[i] = 0;
            }else{
                while(!st.empty() && temperatures[i]>=st.top().first){
                    st.pop();
                }
                if(st.empty()){
                    result[i] = 0;
                }else{
                    pair<int,int > temp = st.top();
                    int first = temp.first;
                    int second = temp.second ;
                    result[i] = abs(second - i);
                }
            }
            st.push({temperatures[i] , i});
        }
        return result;

    }
};