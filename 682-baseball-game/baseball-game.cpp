class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string> st;
        for(string s : operations){
            if(s == "+"){
                int temp1 = stoi(st.top());
                st.pop();
                int temp2 = stoi(st.top());
                st.pop();
                st.push(to_string(temp2));
                st.push(to_string(temp1));
                st.push(to_string(temp1 + temp2));
            }else if(s == "D"){
                string temp = st.top();
                st.push(to_string(2*stoi(temp)));
            }else if(s == "C"){
                st.pop();
            }
            else{
                st.push(s);
            }
        }
        int count =0 ;
        while(!st.empty()){
            count = count + stoi(st.top());
            st.pop();
        }
        return count;
    }
};