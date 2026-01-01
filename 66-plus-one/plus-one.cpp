class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n  = digits.size();
        int ld = digits[n-1] +1;
        digits[n-1]  = ld%10;
        int carry = ld/10;
        for(int i  = n -2 ; i>=0 ; i--){
            int sum = carry + digits[i];
            digits[i] = sum %10;
             carry = sum /10;
        }
        vector<int> result;
        if(carry){  
            result.push_back(1);
            for(int i =0 ; i<n ;i++){
                result.push_back(digits[i]);
            }
            return result;
        }
        return digits;
    }
};