class Solution {
public:

    int isPalindrome(int starting , int ending , string &s,vector<vector<int>> &dp){
        if(starting>=ending) return 1;
        
        if(dp[starting][ending]!= -1){
            return dp[starting][ending];
        }   

        if(s[starting] == s[ending]){
            return dp[starting][ending] = isPalindrome(starting +1 , ending - 1, s, dp);
        }else{
            return dp[starting][ending]=  0;
        }
        
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if(n== 1) return s;
        

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int maxLength =0;
        int startingPoint = 0;
        for(int i =0 ; i<n ; i++){
            for(int j =i ; j<n ;j++){
                if(isPalindrome(i , j , s,dp) && maxLength < j - i +1){
                    maxLength = j - i +1;
                    startingPoint = i;
                }
            }
        }
        return s.substr(startingPoint,maxLength);
    }
};