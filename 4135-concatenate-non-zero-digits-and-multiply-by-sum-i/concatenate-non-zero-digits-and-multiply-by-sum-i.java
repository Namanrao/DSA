class Solution {
    public long sumAndMultiply(int n) {
        if(n == 0){
            return 0;
        }
        int sum = 0 ;
        int new_digit = 0;
        while(n!=0){
            int last_digit = n%10;
            sum += last_digit;
            if(last_digit != 0){
                new_digit = new_digit*10 + last_digit;
            }
            n = n/10;
        }
        int final_digit = 0 ;
        while(new_digit!=0){
            int last_digit = new_digit%10;
            final_digit = final_digit*10 + last_digit;
            new_digit = new_digit/10;
        }
        long result = (long)final_digit*sum;
        return result;
    }
}