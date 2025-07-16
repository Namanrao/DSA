class Solution {
public:
    vector<int> pse(vector<int> &nums){
        int n = nums.size();
        stack<int> st;
        vector<int> left(n);
        for(int i =0 ;i<n; i++){
            while(!st.empty() && nums[st.top()]>= nums[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = -1;
            }else{
                left[i] = st.top();
            }
            st.push(i);
        }
        return left;
    }
    vector<int> nse(vector<int> &nums){
        int n = nums.size();
        stack<int> st;
        vector<int> right(n);
        for(int i=n-1; i>=0 ;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()){
                right[i] = n;
            }else{
                right[i] = st.top();
            }
            st.push(i);
        }
        return right;
    }

    int max_area(vector<int> &nums){
        int n = nums.size();
        vector<int> left = pse(nums);
        vector<int> right = nse(nums);
        int result = 0;
        for(int i = 0;i<n;i++){
            result = max(result,(right[i]-left[i]-1)*nums[i]);
        }
        return result;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> main(m,0);
        
        int area =0;

        for(int i =0 ;i<n ;i++){
            for(int j =0; j<m ;j++){
                //update the main vector
                if(matrix[i][j]=='1'){
                   main[j] = main[j] + 1;
                }else{
                    main[j] = 0;
                }
            }
             // call the normal maximum_rectangle problem for this in 1-D.
                int res = max_area(main);
                area = max(area,res);
        }
        return area;
    }
};