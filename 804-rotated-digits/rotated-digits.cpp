class Solution {
public:

    bool isGood(int n){      
        // check every digit of the number
        int k =0 ; 
        int result =0 ; 
        int temp = n ;
        while(n!=0){
            int lastDigit = n%10;   
            
            if(lastDigit == 3 || lastDigit == 4 || lastDigit == 7  ) return false;
            else if(lastDigit == 2 || lastDigit == 5 || lastDigit == 6 || lastDigit == 9) {
                if(lastDigit == 2){
                    result = result + pow(10,k)*5;
                }else if(lastDigit == 5){
                    result = result + pow(10,k)*2;
                }else if(lastDigit == 6){
                    result = result + pow(10,k)*9;
                }else{
                    result = result + pow(10,k)*6;
                }
            }else{
                result = result + pow(10,k)*lastDigit;
            }
            n = n /10; 
            k++;
        }
        return (result !=temp);
    }

    int rotatedDigits(int n) {
        int result = 0 ;
        for(int i =1 ; i<=n ; i++){
            if(isGood(i)) result++;
        }

        return result;
    }
};