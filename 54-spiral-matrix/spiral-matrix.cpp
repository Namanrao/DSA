class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int n = arr.size() ;
        int m = arr[0].size();

        int left =0 ;
        int right = m -1;
        int top  =0 ;
        int bottom = n -1;
        

        vector<int>result;
        while(left<=right && top <=bottom){
            
            for(int i =left ; i<= right ; i++){
                result.push_back(arr[top][i]);
            }
            top++;

            if(top<=bottom){
                for(int i = top; i<=bottom ; i++){
                    result.push_back(arr[i][right]);
                }
                right --;
            }

            if(left <= right && top<=bottom){
                for(int i = right ; i>= left ; i--){
                    result.push_back(arr[bottom][i]);
                }
                bottom--;
            }

            if(top<=bottom && left<=right){
                for(int i = bottom ; i>=top ; i--){
                    result.push_back(arr[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};