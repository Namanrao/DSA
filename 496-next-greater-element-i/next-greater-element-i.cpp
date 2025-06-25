class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // take action only on nums2 . 
        int n = nums2.size();
        stack<int> st;
        unordered_map<int,int> result;
        for(int i = n-1 ; i>=0 ; i--){
            if(st.empty()){
                result[nums2[i]] = -1;
            }else{
                if(st.top()>nums2[i]){
                    result[nums2[i]] = st.top();
                }else{
                    while(!st.empty() && st.top()<=nums2[i]){
                        st.pop();
                    }
                    if(st.empty()){
                        result[nums2[i]] = -1;
                    }else{
                        result[nums2[i]] = st.top();
                    }
                }
            }
            st.push(nums2[i]);
        }
    vector<int> final;
    for(int i : nums1){
        final.push_back(result[i]);
    }
    return final;
    }
};