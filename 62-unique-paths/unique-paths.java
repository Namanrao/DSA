class Solution {
        // tabulation + memoization

    public int solve(int n , int m){
        int [][] dp = new int [n+1][m+1];
        for(int i= 0; i<n ;i++){
            for(int j =0;j<m;j++){
                if(i==0 || j==0 ){
                    dp[i][j] =1;
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
                    return dp[n-1][m-1];

    }
    public int uniquePaths(int m, int n) {
        int result =solve(n,m);
        return result;
    }
}