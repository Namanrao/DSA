class Solution {
    // tabulation
    public int solve(int[][] obstacleGrid, int n , int m){
        // if starting point is itself an obstacle.
        if(obstacleGrid[0][0]==1){
            return 0 ;
        }
        int dp [][] = new int [n+1][m+1];

        dp[0][0] = 1;
        for(int i =0 ;i<n ; i++){
            for(int j =0;j<m;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j]  = 0;
                }else{
                    if(i>0){
                        dp[i][j]+=dp[i-1][j];
                    }
                    if(j>0){
                        dp[i][j]+=dp[i][j-1];
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n = obstacleGrid.length;
        int m = obstacleGrid[0].length;
        int i=n-1 , j =m-1;
        int result = solve(obstacleGrid, n , m);
        return result;
    }
}